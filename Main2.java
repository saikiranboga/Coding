import java.util.*;

class Node implements Comparable<Node>{
    int index;
    int depth;
    public Node(int index,int depth){
        this.index=index;
        this.depth=depth;
    }


    public int compareTo(Node o) {
        return depth>o.depth? 1:-1;
    }
}

public class Main  {
    
    public static void main(String[] args) {
	new Main().run();
    }

    public void run() {
	///// input starts from here

	Scanner in = new Scanner(System.in);

	int max = 0, start = 0,t = 0;
	int N = in.nextInt();

	boolean arr[][] = new boolean[N][N];
	boolean visited[] = new boolean[N];
	int[] value = new int[N];
	List[] lst = new List[N];

	for( int i = 0; i < N; i++ ){
	    lst[i] = new ArrayList<Integer>();
	}

	Arrays.fill(value, 0);
	Arrays.fill(visited,false);

	for(int i=0;i<N-1;i++){
	    int n=in.nextInt()-1;
	    int m=in.nextInt()-1;
	    lst[n].add(m);    //these are adjacency list
	    lst[m].add(n);    //
				
	}
	/////// input end

	start=0;
	///////////////////////////////////   getting the first node from root
	PriorityQueue<Node> pq=new PriorityQueue<Node>();
	pq.add(new Node(start,0));
	visited[start]=true;
	while(!pq.isEmpty()){
	    Node nd=pq.poll();
	    int ind=nd.index;
	    int dep=nd.depth;
	    for(int i=0;i<lst[ind].size();i++){
		t=Integer.parseInt(lst[ind].get(i).toString());
		if(!visited[t])
                    {
			visited[t]=true;
                        value[t]=dep+1;
                        Node nw=new Node(t,dep+1);
                        pq.add(nw);
                    }
	    }
	}

	///////////////////////////////////


	for(int i=0;i<N;i++){
	    if(value[i]>max){
		max=value[i];
		start=i;                      ///////////////////now start is the new point to start from
	    }
	}
	Arrays.fill(value, 0);
	Arrays.fill(visited,false);

	///////////////////////////////////    final search
			
	pq.add(new Node(start,0));
	visited[start]=true;
	while(!pq.isEmpty()){
	    Node nd=pq.poll();
	    int ind=nd.index;
	    int dep=nd.depth;
	    for(int i=0;i<lst[ind].size();i++){
		t=Integer.parseInt(lst[ind].get(i).toString());
		if(!visited[t])
                    {
			visited[t]=true;
                        value[t]=dep+1;
                        Node nw=new Node(t,dep+1);
                        pq.add(nw);
                    }
	    }
	}
	///////////////////////////////////

	for(int i=0;i<N;i++){
	    if(value[i]>max){
		max=value[i];
	    }
	}
	System.out.println(max);

    }

}
