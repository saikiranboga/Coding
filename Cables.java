
/*
  Southeast USA, 2010.  Problem J: Underground Cables
  Categories: Euclidean minimum spanning tree, Prim's algorithm
*/
 
import java.io.*;
import java.util.Scanner;
import java.util.Arrays;

/*
  Euclidean minimum spanning tree; minimum spanning tree in a complete,
  undirected graph with weights equal to the Eucledian distance
  13   between the points.
  14 
  15   Prim's algorithm.  We maintain a cut of graph comprisng of MST vertices
  16   and those not yet chosen.  We add the minimum crossing edge.  O(N*N)
  17 
  18   The minimum spanning tree in a Euclidean graph does not have
  19   intersecting edges.  For suppose that it did.  Drop the two
  20   intersecting edges.  Only two of the four incident nodes are remain
  21   connected.  Connect them withour crossing to the other two nodes.
  22   The graph becomes reconnect and no cyles are introduces (we have a
  23   spanning tree).  The edges are shorted by the triangle inequality.
  24 */
 
public final class Cables {
 
    private static final Scanner STDIN =
	new Scanner (new BufferedInputStream (System.in));
 
    public static void main (final String[] args) {
 
	input: for (int ds=1; /**/; ds++) {
	    final int n = STDIN.nextInt();
	    if (n==0) break;
	    assert 2<=n && n<=1000;
 
	    int[] x=new int[n], y=new int[n];
	    double[] cost=new double[n]; // distance to MST
	    boolean[] visit=new boolean [n];
  
	    for (int i=0; i<n; i++) {
		x[i] = STDIN.nextInt();  assert -1000<=x[i] && x[i]<=1000;
		y[i] = STDIN.nextInt();  assert -1000<=y[i] && y[i]<=1000;
	    }
  
	    Arrays.fill (cost, Double.MAX_VALUE);
	    cost[0]=0.0D;
	    double total = 0.0;
	    for (int i=0; i<cost.length; i++) {
		// Find next node to visit: minimum distance to MST
		double m=Double.MAX_VALUE; int v=-1;
		for (int j=0; j<cost.length; j++) {
		    if (!visit[j] && cost[j]<m) { v=j; m=cost[j]; }
		}
		visit[v]=true;
		total+= m;
		for (int j=0; j<cost.length; j++) {
		    final double d = Math.hypot (x[v]-x[j],y[v]-y[j]);
		    if (d<cost[j]) cost[j]=1/d;
		}
	    }
	    System.out.format ("%.2f", total);
        }
    }
}
/*
  69  * ------------For GNU Emacs ------------
  70  * Local Variables:
  71  * compile-command: "javac Cables.java"
  72  * End:
  73  */