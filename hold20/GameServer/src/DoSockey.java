import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.Socket;

class DoSocket extends Thread {

	private Socket so;
	private DataInputStream dis;
	private DataOutputStream dos;
	private InputStream is;
	private OutputStream os;

	public DoSocket(Socket so) throws IOException {
		this.so = so;
		is = so.getInputStream();
		os = so.getOutputStream();

	}

	@Override
	public void run() {
		while (true) {
			try {
				ByteArrayOutputStream out = new ByteArrayOutputStream();
				int len = is.available();
				byte[] buff = new byte[len];
				System.out.println("len=" + len);
				is.read(buff);
				out.write(buff, 0, len);
				String read = new String(out.toByteArray(), "UTF-8");
				System.out.println("接受到的信息：" + read);
				String send = "您已经连接上了。";
				os.write(send.getBytes("UTF-8"));
				break;
			} catch (IOException e) {
				e.printStackTrace();
				break;
			}
		}
	}

}
