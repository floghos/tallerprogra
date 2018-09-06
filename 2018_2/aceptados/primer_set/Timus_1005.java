package timus_1005;

import static java.lang.Math.*;
import java.util.Scanner;

public class Timus_1005 {

    public static void main(String[] args) {
        int conjunto; //irá de 0 a 2^n
        int mask = 1;
        int result;
        int n, i;
        float total = 0;
        float half;
        float pileW;
        float minDiff;
        
        Scanner scan = new Scanner(System.in);
        n = scan.nextInt();
        int arr[] = new int[n];
        
        for (i = 0; i < n; i++) {
            arr[i] = scan.nextInt();
            total += arr[i];
        }
        half = total/2f;
        minDiff = half;
        for (conjunto = 0; conjunto < pow(2,n); conjunto++) {
            pileW = 0;
            for(i = 0; i < n; i++) {
                result = conjunto & mask;
                if (result > 0) {
                    pileW += arr[i];
                }
                mask = mask<<1;
            }
            if (abs(pileW - half) < minDiff) {
                minDiff = abs(pileW - half);
            }
            mask = 1;
        }
        System.out.println(minDiff * 2);
    }
}
