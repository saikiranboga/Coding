import java.util.*;
import java.io.*;
 
public class TRIQUERY{
 
    public static void main(String[] args)throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int Q = Integer.parseInt(st.nextToken());
        HashMap<Integer,HashMap<Integer,Integer>> points = new HashMap<Integer,HashMap<Integer,Integer>>(N);
 
	HashMap<Integer,Integer> tmp;
 
        for(int i=0; i<N; i++){
            st = new StringTokenizer(br.readLine());
	    int t = Integer.parseInt(st.nextToken());
	    if(points.containsKey(t) == false){
		tmp = new HashMap<Integer,Integer>();
		tmp.put(Integer.parseInt(st.nextToken()),0);
		points.put(t,tmp);
	    }
	    else{
		tmp = points.get(t);
		tmp.put(Integer.parseInt(st.nextToken()),0);
	    }
        }
	int x,y,d;
	int j,k,count,x1,y1,sum;
        for(int i=0; i<Q; i++){
            st = new StringTokenizer(br.readLine());
	    x = Integer.parseInt(st.nextToken());
	    y = Integer.parseInt(st.nextToken());
	    d = Integer.parseInt(st.nextToken());


	    count=0;
	    //	    HashMap<Integer,Integer> tmp;
	    x1 = x+d;
	    y1 = y+d;
	    sum = x1+y;
	    for(k=x;k<=x1;k++){
		if(points.containsKey(k) == true){
		    tmp = points.get(k);
		    for(j=y;j<=y1;j++)
			if(tmp.containsKey(j) == true){
			    if(k+j <= sum)
				count++;
			}
		}
	    }
	    System.out.println(count);
	    //   result(points,x,y,d);
	}
    }
 
 
    //    public static void result(HashMap<Integer,HashMap<Integer,Integer>> hm,int x,int y,int d){
    // }
    
 
 
} 