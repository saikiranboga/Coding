import java.util.*;

public class AddingGroupsCollections{
    public static void main(String[] args){
	Collection<Integer> coll = new ArrayList<Integer>(Arrays.asList(2,3,4,5));

	Integer[] moreInts = {6,7,8,9,10};

	coll.addAll(Arrays.asList(moreInts));

	for(Integer i: coll){
	    System.out.print(i + " ");
	}

	Collections.addAll(coll,11,12,13,14,15);
	Collections.addAll(coll,moreInts);

	List<Integer> list = Arrays.asList(16,17,18,19,20);
	list.set(1,99);
	list.add(21);

	for(Integer i: coll){
	    System.out.print(i + " ");
	}
    }
}