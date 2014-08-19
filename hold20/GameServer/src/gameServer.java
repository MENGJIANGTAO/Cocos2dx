import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.sql.Connection;

public class gameServer {

	public static void main(String[] args) {
		ServerSocket ss = null;
		try {
			ss = new ServerSocket(9777);
		} catch (Exception e) {
			e.printStackTrace();
		}
		System.out.println("ServerStarting.....");

		while (true) {
			try {
				Socket so = ss.accept();
//				so.setSoTimeout(2000);
				if (so == null) {
					continue;
				}
				System.out.print("recevie a msg.");
				new DoSocket(so).start();
			} catch (Exception e) {
				e.printStackTrace();
			}
		}
	}
}
