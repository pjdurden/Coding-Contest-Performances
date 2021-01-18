import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
    public static void main (String[] args) throws java.lang.Exception
    {
        Scanner scan = new Scanner(System.in);
        int ls = scan.nextInt();
        while(ls-- !=0){
            int n = scan.nextInt();
            int k = scan.nextInt();
            int arr[] = new int[n];
            LinkedHashSet<Integer> linkedhs1 = new LinkedHashSet<Integer>();
            
            int sum = 0;
            for(int i = 0; i < n; i++){
                arr[i] = scan.nextInt();
            }
            Arrays.sort(arr);
            linkedhs1.add(arr[n - 1]);
            sum=arr[n - 1];
            int temp = -1;
            for(int i = n - 2; i >= 0; i--){
                LinkedHashSet<Integer> linkedhs2 = new LinkedHashSet<Integer>();
                sum = sum + arr[i];
                Iterator i1 = linkedhs1.iterator();
                while(i1.hasNext()){
                    int p=(int)(i1.next());
                    linkedhs2.add(p);
                    linkedhs2.add(arr[i]);
                    linkedhs2.add(p + arr[i]);
                    if(((p + arr[i]) >= k) && ((sum - p - arr[i]) >= k)){
                        temp = n - i;
                        break;
                    }
                    if(((arr[i]) >= k) && ((sum - arr[i]) >= k)){
                        temp = n - i;
                        break;
                    }
                }
                if(temp != -1){
                    break;
                }
                linkedhs1 = linkedhs2;
            }
            System.out.println(temp);
        }
    }
}
