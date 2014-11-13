import java.util.*;
 
public class LongestPathInTree {
   //tree is represented as an adjacent list
   private List<List<Integer>> adjacentList;
   private Path longestPath;
   //is a node visited?
   private boolean[] visited;
 
   public LongestPathInTree (List<List<Integer>> adjacentList) {
       this.adjacentList = adjacentList;
       this.visited = new boolean[adjacentList.size()];
   } 
 
   public Path getLongestPath() {
       return longestPath;
   }
 
   //traverse paths between every pair of nodes
   public void bruteForceMethod() {
       //default path is shortest
       longestPath = new Path();
       for(int i = 0; i < adjacentList.size(); i++) {
           Arrays.fill(visited,false);
           depthFirstSearchPath(i,i,0);
       }
   }
 
   public void depthFirstSearchPath(int treeRoot, int subTreeRoot, int pathLength) {
         List<Integer> neighbors = adjacentList.get(subTreeRoot);
     //in fact, only leave nodes need checking but it does not harm to check every node
     if(pathLength > longestPath.getLength()) {
         longestPath.setStart(treeRoot);
         longestPath.setEnd(subTreeRoot);
         longestPath.setLength(pathLength);
     }
     for(int u : neighbors) {
         if(!visited[u]) {
         visited[u] = true;
         depthFirstSearchPath(treeRoot, u, pathLength+1);
         }
     }
   }
 
   public void dpMethod() {
       Arrays.fill(visited,false);
       int root = 0;
       longestPath = findLongestPath(root)[0];
   }
 
   public Path[] findLongestPath(int root) {
       visited[root] = true;
       //longest path in subtrees (don't have to pass the subtree root)
       Path longestPathInSubtrees = null;
       //longest path from a subtree root  to a leave
       Path longestPathFromSubrootToSubLeave = null;
       //second longest path from another subtree root to a leave
       //the two subtrees must be different
       Path secondLongestPathFromSubrootToSubLeave = null;
       List<Integer> neighbors = adjacentList.get(root);
       //System.out.println(neighbors);
       for(int u : neighbors) {
           if(!visited[u]) {
           //path[0] is the longest path in a subtree
           //path[1] is the longest path from the subtree root to a leave
           Path[] paths = findLongestPath(u);
           if(longestPathInSubtrees == null
               || longestPathInSubtrees.getLength() < paths[0].getLength()) {
               longestPathInSubtrees = paths[0];
           }
           if(longestPathFromSubrootToSubLeave == null
             || longestPathFromSubrootToSubLeave.getLength() < paths[1].getLength()) {
           secondLongestPathFromSubrootToSubLeave = longestPathFromSubrootToSubLeave;
           longestPathFromSubrootToSubLeave = paths[1];
           } else if(secondLongestPathFromSubrootToSubLeave == null
             || secondLongestPathFromSubrootToSubLeave.getLength() < paths[0].getLength() ) {
           secondLongestPathFromSubrootToSubLeave = paths[1];
           }
       }
       }
       //System.out.println("Root: " + root);
       //System.out.println(longestPathFromSubrootToSubLeave);
       //System.out.println(secondLongestPathFromSubrootToSubLeave);
       if (longestPathFromSubrootToSubLeave == null
            && secondLongestPathFromSubrootToSubLeave == null) {
        //leave
           return new Path[] {new Path(root, root, 0), new Path(root, root, 0)};
       }else {
       //the potential longest path passing root
       Path path = null;
       //this node might only have one subtree
       if(secondLongestPathFromSubrootToSubLeave == null) {
           path = new Path(longestPathFromSubrootToSubLeave.getEnd(),
                        root, longestPathFromSubrootToSubLeave.getLength()+1);
       }else {
           path = new Path(longestPathFromSubrootToSubLeave.getEnd(),
                secondLongestPathFromSubrootToSubLeave.getEnd(),
                longestPathFromSubrootToSubLeave.getLength() + 1
                + secondLongestPathFromSubrootToSubLeave.getLength() + 1);
       }
       Path[] paths = new Path[2];
       //the longest path in the tree
       paths[0] = path.getLength() > longestPathInSubtrees.getLength() ? path : longestPathInSubtrees;
       //the longest path from the root to a leave
       paths[1] = new Path(root, longestPathFromSubrootToSubLeave.getEnd(),
                    longestPathFromSubrootToSubLeave.getLength()+1);
       return paths;
       }
   }
 
   public void farthestFarthestMethod() {
       longestPath = new Path();
       int root = 0;
       Arrays.fill(visited,false);
       depthFirstSearchPath(root, root, 0);
       Arrays.fill(visited,false);
       root = longestPath.getEnd();
       Arrays.fill(visited, false);
       depthFirstSearchPath(root, root, 0);
   }
 
   public static void main(String[] args) {
       List<List<Integer>> tree = new ArrayList<List<Integer>>();
       List<Integer> ls0 = new ArrayList<Integer>();
       ls0.add(1);
       ls0.add(2);
       ls0.add(3);
       tree.add(ls0);
       List<Integer> ls1 = new ArrayList<Integer>();
       ls1.add(0);
       ls1.add(4);
       ls1.add(5);
       tree.add(ls1);
       List<Integer> ls2 = new ArrayList<Integer>();
       ls2.add(0);
       ls2.add(6);
       tree.add(ls2);
       List<Integer> ls3 = new ArrayList<Integer>();
       ls3.add(0);
       tree.add(ls3);
       List<Integer> ls4 = new ArrayList<Integer>();
       ls4.add(1);
       ls4.add(7);
       tree.add(ls4);
       List<Integer> ls5 = new ArrayList<Integer>();
       ls5.add(1);
       ls5.add(9);
       tree.add(ls5);
       List<Integer> ls6 = new ArrayList<Integer>();
       ls6.add(2);
       ls6.add(8);
       tree.add(ls6);
       List<Integer> ls7 = new ArrayList<Integer>();
       ls7.add(4);
       ls7.add(13);
       tree.add(ls7);
       List<Integer> ls8 = new ArrayList<Integer>();
       ls8.add(6);
       tree.add(ls8);
       List<Integer> ls9 = new ArrayList<Integer>();
       ls9.add(5);
       ls9.add(10);
       tree.add(ls9);
       List<Integer> ls10 = new ArrayList<Integer>();
       ls10.add(9);
       ls10.add(11);
       tree.add(ls10);
       List<Integer> ls11 = new ArrayList<Integer>();
       ls11.add(10);
       ls11.add(12);
       tree.add(ls11);
       List<Integer> ls12 = new ArrayList<Integer>();
       ls12.add(11);
       tree.add(ls12);
       List<Integer> ls13 = new ArrayList<Integer>();
       ls13.add(7);
       ls13.add(14);
       tree.add(ls13);
       List<Integer> ls14 = new ArrayList<Integer>();
       ls14.add(13);
       ls14.add(15);
       tree.add(ls14);
       List<Integer> ls15 = new ArrayList<Integer>();
       ls15.add(14);
       tree.add(ls15);
       LongestPathInTree finder = new LongestPathInTree(tree);
       finder.bruteForceMethod();
       System.out.println(finder.getLongestPath());
       finder.dpMethod();
       System.out.println(finder.getLongestPath());
       finder.farthestFarthestMethod();
       System.out.println(finder.getLongestPath());
   }
}
 
class Path {
    private int start;
    private int end;
    private int length;
 
    public Path() {
        this.start = Integer.MIN_VALUE;
    this.end = Integer.MIN_VALUE;
    this.length = Integer.MIN_VALUE;
    }
 
    public Path(int start, int end, int length) {
        this.start = start;
    this.end = end;
    this.length = length;
    }
 
    public int getStart() {
        return start;
    }
 
    public int getEnd() {
        return end;
    }
 
    public int getLength() {
        return length;
    }
 
    public void setStart(int start) {
        this.start = start;
    }
 
    public void setEnd(int end) {
        this.end = end;
    }
 
    public void setLength(int length) {
        this.length = length;
    }
 
    public String toString() {
        return "start: " + start + " end: " + end + " length: " + length;
    }
 
}