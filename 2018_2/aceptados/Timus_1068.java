package timus_1068;

import java.util.Scanner;

public class Timus_1068 {

    public static void main(String[] args) {
        int n, dir, i;
        int sum = 0;
        Scanner scan = new Scanner(System.in);
        n = scan.nextInt();
        dir = (n < 1)? -1 : 1;
        for (i = 1; i != (n+dir); i += dir) {
            sum += i;
        }
        System.out.println(sum);
    }
}
