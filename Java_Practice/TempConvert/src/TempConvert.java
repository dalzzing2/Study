import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import java.awt.Button;
import java.awt.TextField;
import java.awt.Label;


public class TempConvert extends JFrame {

	private JPanel contentPane;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					TempConvert frame = new TempConvert();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the frame.
	 */
	public TempConvert() {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 450, 300);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		Button button = new Button("Convert");
		button.setBounds(68, 161, 87, 25);
		contentPane.add(button);
		
		TextField textField = new TextField();
		textField.setBounds(68, 117, 87, 25);
		contentPane.add(textField);
		
		Label label = new Label("Celsius");
		label.setBounds(200, 117, 77, 25);
		contentPane.add(label);
		
		Label label_1 = new Label("Fahrenheit");
		label_1.setBounds(200, 161, 77, 25);
		contentPane.add(label_1);
		
		button.addActionListener(new java.awt.event.ActionListener(){
			public void actionPerformed(java.awt.event.ActionEvent evt){
				int tempFahr = (int)((Double.parseDouble(textField.getText()))*1.8+32);
				label_1.setText(tempFahr + " Fahrenheit");
			}
		});
		
	}
}
