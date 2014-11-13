#include <iostream>
using namespace std;

public class maxSubMatrix{
    public optGroup MaxSubMatrix(int[][] a){
        int m = a.length;
        int n = a[0].length;
        optGroup opt=new optGroup();
        int[] line = new int[n];
        for(int i=0;i&lt;a.length;i++) {
            for(int k=0;k&lt;n;k++){
                line[k]=0; // reset line for each i
            }
            for(int j=i;j&lt;m;j++){
                for(int k=0;k&lt;n;k++){
                    line[k]=line[k]+a[j][k]; // accumulate line from previous j
                }
                // solve maximum subarray problem on line [0 ... n-1]
                optTriple optcur = FineMaxSubArray(line); 
                if (opt.opt&gt;optcur.opt){
                    opt.opt= optcur.opt;
                    opt.left = optcur.left;
                    opt.right = optcur.right;
                    opt.low= i;
                    opt.high = j;
                }
            }
        }
        return opt;
    }
    public static class optTriple{
        int opt;
        int left;
        int right;
    };
    public static class optGroup{
        int opt;
        int left;
        int right;
        int low;
        int high;
    };
};

int main(){
    maxSubMatrix 
    return 0;
}