package timus_1001;

import java.util.*;

public class Timus_1001 {

    public static void main(String[] args) {
        Recursive r = new Recursive();
        Scanner scanner = new Scanner(System.in);
        
        if (scanner.hasNextInt()) {
            r.main();
        }
    }

}
class Recursive {
    public Recursive() {
     
    }
    public void main() {
        int num;
        Recursive r = new Recursive();
        Scanner scanner = new Scanner(System.in);
        num = scanner.nextInt();
        if (scanner.hasNextInt()) {
            r.main();
        } else {
            
        }
        System.out.println(Math.sqrt(num));
    }
}
