import java.io.*;
class Pruefer {
    static int k,l,n;
    static long count;

    public static void main (String [] args)throws IOException {
        BufferedReader x=new BufferedReader(new InputStreamReader(System.in));
        String p[]=x.readLine().split(" ");
        k = Integer.parseInt (p[0]);
        l = Integer.parseInt (p[1]);
        n = k * l;
        degrees = new int [n];
        recurse (new int [n - 2],0);

        System.out.println (count);
    }

    static void recurse (int [] code,int i) {
        if (i == code.length)
            handle (code);
        else
            for (code [i] = 0;code [i] < n;code [i]++)
                recurse (code,i + 1);
    }

    static int [] degrees;
    static boolean valid;
    
    static void handle (int [] code) {
        for (int i = 0;i < degrees.length;i++)
            degrees [i] = 1;
        for (int c : code)
            degrees [c]++;
        
        valid = true;

        for (int c : code)
            for (int i = 0;i < n;i++)
                if (degrees [i] == 1) {
                    insertEdge (c,i);
                    degrees [c]--;
                    degrees [i]--;
                    break;
                }

        // add edge between last two nodes with degree 1
        for (int i = 0;i < degrees.length;i++)
            if (degrees [i] == 1)
                for (int j = i + 1;j < degrees.length;j++)
                    if (degrees [j] == 1) {
                        insertEdge (i,j);
                        if (valid)
                            count++;
                        return;
                    }
    }

    static void insertEdge (int i,int j) {
        valid &= (i % k) != (j % k);
    }
}