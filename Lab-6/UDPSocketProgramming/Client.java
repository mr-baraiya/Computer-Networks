import java.net.*;
import java.io.*;

public class Client {
    public static void main(String[] args) {
        DatagramSocket socket = null;
        BufferedReader reader = null;

        try {
            socket = new DatagramSocket();
            InetAddress ip = InetAddress.getByName("127.0.0.1");
            reader = new BufferedReader(new InputStreamReader(System.in));

            String message = "";
            while (!message.equals("Over")) {
                System.out.print("Enter message: ");
                message = reader.readLine();

                byte[] buffer = message.getBytes();
                DatagramPacket packet = new DatagramPacket(buffer, buffer.length, ip, 5000);
                socket.send(packet);
            }
        } catch (Exception e) {
            System.out.println("Error: " + e);
        } finally {
            if (socket != null) socket.close();
            try {
                if (reader != null) reader.close();
            } catch (IOException e) {
                System.out.println(e);
            }
        }
    }
}
