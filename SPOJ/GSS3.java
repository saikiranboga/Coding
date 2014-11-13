import java.io.*;
import java.lang.*;
import java.util.Scanner;

class Node {
    int lsum, rsum, sum, maxs;
}
class SegTree {
    public int MAXN = 50005;
    public Node[] tree = new Node[4 * MAXN];
    public int[] A = new int[MAXN];
    public int N = 0;

    public SegTree(int N) {
        this.N = N;
    }

    public void initialize(int node_num, int st, int ed) {
        tree[node_num] = new Node();
        if (st == ed) {
            tree[node_num].lsum = A[st];
            tree[node_num].rsum = A[st];
            tree[node_num].sum = A[st];
            tree[node_num].maxs = A[st];
            return;
        }
        int mid = (st + ed) / 2;
        initialize(node_num * 2, st, mid);
        initialize(node_num * 2 + 1, mid + 1, ed);
        update_val(node_num);
        return;
    }

    public void update_val(int node_num) {
        tree[node_num].lsum = Math.max(tree[node_num * 2].lsum, tree[node_num * 2].sum + tree[node_num * 2 + 1].lsum);
        tree[node_num].rsum = Math.max(tree[node_num * 2 + 1].rsum, tree[node_num * 2].rsum + tree[node_num * 2 + 1].sum);
        tree[node_num].sum = tree[node_num * 2].sum + tree[node_num * 2 + 1].sum;
        tree[node_num].maxs = Math.max(tree[node_num * 2].maxs, tree[node_num * 2 + 1].maxs);
        tree[node_num].maxs = Math.max(tree[node_num].maxs, tree[node_num * 2].rsum + tree[node_num * 2 + 1].lsum);
        return;
    }

    public boolean update(int node_num, int st, int ed, int pos, int val) {
        if (pos > ed || pos < st)
            return false;
        if (st == ed && st == pos) {
            A[st] = val;
            tree[node_num].lsum = A[st];
            tree[node_num].rsum = A[st];
            tree[node_num].sum = A[st];
            tree[node_num].maxs = A[st];
            return true;
        }
        int mid = (st + ed) / 2;
        boolean left_changed = false, right_changed = false;
        left_changed = update(node_num * 2, st, mid, pos, val);
        right_changed = update(node_num * 2 + 1, mid + 1, ed, pos, val);
        if (left_changed || right_changed) {
            update_val(node_num);
            return true;
        }
        return false;
    }

    public Node query(int node_num, int st, int ed, int i, int j) {
        if (st == i && ed == j)
            return tree[node_num];
        int mid = (st + ed) / 2;

        if (j <= mid) {
            return query(node_num * 2, st, mid, i, j);
        }

        if (i > mid) {
            return query(node_num * 2 + 1, mid + 1, ed, i, j);
        }

        Node left = query(node_num * 2, st, mid, i, mid);
        Node right = query(node_num * 2 + 1, mid + 1, ed, mid + 1, j);

        Node ret = new Node();
        ret.lsum = Math.max(left.lsum, left.sum + right.lsum);
        ret.rsum = Math.max(right.rsum, left.rsum + right.sum);
        ret.sum = left.sum + right.sum;
        ret.maxs = Math.max(left.maxs, right.maxs);
        ret.maxs = Math.max(ret.maxs, left.rsum + right.lsum);
        return ret;
    }
}

class Reader {
    private static final int SIZE = 1<<13;private static InputStream in = System.in;private int offSet;private int bufferSize;private byte[] buffer;private char[] charBuffer;public Reader(){buffer = new byte[SIZE];charBuffer = new char[SIZE];}
    public int readInt(){
        int number=0;boolean neg=false;
        try{
            if(offSet==bufferSize){offSet=0;bufferSize=in.read(buffer);}
            for(;offSet<bufferSize&&buffer[offSet] != '-' && buffer[offSet] < '0'; offSet++){if(offSet==bufferSize-1){offSet = -1;bufferSize=in.read(buffer);}}
            if(buffer[offSet] == '-') {
                neg = true;
                offSet++;
                if(offSet == bufferSize) {
                    offSet=0;bufferSize=in.read(buffer);
                }
            }for(;offSet<bufferSize&&buffer[offSet]>='0'&&buffer[offSet]<='9';offSet++) {
                number=number*10-'0'+buffer[offSet];
                if(offSet==bufferSize-1){offSet = -1;bufferSize=in.read(buffer);}
            }offSet++;
        }catch(IOException io){io.printStackTrace();System.exit(0);}
        return neg ? -number : number;
    }
}

public class GSS3 {
    public static void main(String[] args) throws IOException {
        Reader rd = new Reader();
        int N = rd.readInt();

        SegTree ST = new SegTree(N);

        for(int i=1;i<=N;i++){
            ST.A[i] = rd.readInt();
        }

        ST.initialize(1, 1, N);
        int Q = rd.readInt();
        int type, x, y;

        while (Q-- > 0) {
            type = rd.readInt();
            x = rd.readInt();
            y = rd.readInt();
            if(type==0)
                ST.update(1, 1, N, x, y);
            else {
                Node ans = ST.query(1, 1, N, x, y);
                System.out.println(ans.maxs);
            }
        }
    }
}