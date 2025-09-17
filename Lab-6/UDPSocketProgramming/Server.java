import java.net.*;

public class Server {
    public static void main(String[] args) {
        DatagramSocket socket = null;
        try {
            socket = new DatagramSocket(5000);
            System.out.println("UDP Server started. Waiting for messages...");

            byte[] buffer = new byte[1024];
            DatagramPacket packet = new DatagramPacket(buffer, buffer.length);

            String receivedMessage = "";
            while (!receivedMessage.equals("Over")) {
                socket.receive(packet); // Receive packet
                receivedMessage = new String(packet.getData(), 0, packet.getLength());
                System.out.println("Client: " + receivedMessage);
            }

            System.out.println("Connection ended by client.");
        } catch (Exception e) {
            System.out.println("Error: " + e);
        } finally {
            if (socket != null) socket.close();
        }
    }
}
