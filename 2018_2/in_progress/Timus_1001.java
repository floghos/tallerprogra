package timus_1001;

import static java.lang.Math.sqrt;
import java.util.*;

public class Timus_1001 {
static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        long n = scanner.nextInt();
        if (scanner.hasNextInt()) {
            recursive();
        }
        double res = sqrt(n);
        System.out.printf("%.4f", res);
        System.out.println();
    }
    
    private static void recursive() {
        long n = scanner.nextInt();
        if (scanner.hasNextInt()) {
            recursive();
        }
        double res = sqrt(n);
        System.out.printf("%.4f", res);
        System.out.println();
    }

}
