import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Scanner;
import java.util.TimeZone;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long time = sc.nextLong();
        Date date = new Date(time);
        SimpleDateFormat fmt = new SimpleDateFormat("HH:mm:ss");
        fmt.setTimeZone(TimeZone.getTimeZone("UTC"));
        System.out.println(fmt.format((date)));
    }
}
