package timus_1025;

import java.util.Scanner;

public class Timus_1025 {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int k = scan.nextInt();
        int group[] = new int[k];
        int i, j, aux;
        
        for (i = 0; i < k; i++) {
            group[i] = scan.nextInt();
        }
        for (i = 0; i < k; i++) { //ordenamos los grupos de más pequeño a más grande
            for (j = i; j < k; j++) {
                if (group[j] < group[i]) {
                    aux = group[j];
                    group[j] = group[i];
                    group[i] = aux;
                }
            }
        }
        int cantMin = 0;
        for (i = 0; i < (k/2)+1; i++) {
            cantMin += (group[i]/2 + 1);
        }
        System.out.println(cantMin);
    }

}
