import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        BigInteger ans = new BigInteger("1");
        for (int i = n + 2; i <= 2 * n; i++)
            ans = ans.multiply(new BigInteger(String.valueOf(i)));
        for (int i = 1; i <= n; i++)
            ans = ans.divide(new BigInteger(String.valueOf(i)));

        System.out.println(ans);
    }

}