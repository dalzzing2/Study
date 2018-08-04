import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JFileChooser;
import javax.swing.JOptionPane;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JMenuBar;
import javax.swing.JMenu;
import javax.swing.JMenuItem;

import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class FileManager extends JFrame {

	private JPanel contentPane;
	private JScrollPane scrollPane;
	private JTextArea textArea;
	private JMenuBar menuBar;
	private JMenu mnFile;
	private JMenu mnAbout;
	private JMenuItem mntmNew;
	private JMenuItem mntmOpen;
	private JMenuItem mntmSave;
	private JMenuItem mntmClose;
	private JMenuItem mntmQuit;
	private JMenuItem mntmAboutTextEditor;

	private JFileChooser fileChooser = new JFileChooser();
	private File file;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					FileManager frame = new FileManager();
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
	public FileManager() {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 1086, 957);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		contentPane.setLayout(new BorderLayout(0, 0));
		setContentPane(contentPane);
		contentPane.add(getScrollPane(), BorderLayout.CENTER);
	}

	private JScrollPane getScrollPane() {
		if (scrollPane == null) {
			scrollPane = new JScrollPane();
			scrollPane.setViewportView(getTextArea());
			scrollPane.setColumnHeaderView(getMenuBar_1());
		}
		return scrollPane;
	}

	private JTextArea getTextArea() {
		if (textArea == null) {
			textArea = new JTextArea();
		}
		return textArea;
	}

	private JMenuBar getMenuBar_1() {
		if (menuBar == null) {
			menuBar = new JMenuBar();
			menuBar.add(getMnFile());
			menuBar.add(getMnAbout());
		}
		return menuBar;
	}

	private JMenu getMnFile() {
		if (mnFile == null) {
			mnFile = new JMenu("File");
			mnFile.add(getMntmNew());
			mnFile.add(getMntmOpen());
			mnFile.add(getMntmSave());
			mnFile.add(getMntmClose());
			mnFile.add(getMntmQuit());
		}
		return mnFile;
	}

	private JMenu getMnAbout() {
		if (mnAbout == null) {
			mnAbout = new JMenu("About");
			mnAbout.add(getMntmAboutTextEditor());
		}
		return mnAbout;
	}

	private JMenuItem getMntmNew() {
		if (mntmNew == null) {
			mntmNew = new JMenuItem("New");
			// New 액션 리스너
			mntmNew.addActionListener(new ActionListener() {
				public void actionPerformed(ActionEvent e) {
					// 파일 오픈 다이얼로그를 띄운다.
					int retval = fileChooser.showDialog(contentPane, "New");
					if (retval == JFileChooser.APPROVE_OPTION) {
						// 선택한 파일의 경로를 반환한다.
						file = fileChooser.getSelectedFile();
						textArea.setText("");
					}

				}
			});
		}
		return mntmNew;
	}

	private JMenuItem getMntmOpen() {
		if (mntmOpen == null) {
			mntmOpen = new JMenuItem("Open");
			// Open 액션 리스너
			mntmOpen.addActionListener(new ActionListener() {
				public void actionPerformed(ActionEvent e) {
					int retval = fileChooser.showOpenDialog(contentPane);

					if (retval == JFileChooser.APPROVE_OPTION) {
						file = fileChooser.getSelectedFile();
						try {
							// 선택된 파일인풋 스트림의 파일 인스턴스를 인풋스트림리더의 인스턴스로 전달
							InputStreamReader isr = new InputStreamReader(
									new FileInputStream(file));
							int ch;
							// ch (즉 문자 한글자를 읽는 경우) 읽어지면 1, 안읽어지면 -1
							while ((ch = isr.read()) != -1) {
								textArea.append((char) ch + "");
							}
							// C언어 파일과 같은개념이라 파일이 끝났으면 close로 종료.
							isr.close();
						} catch (FileNotFoundException e1) {
							System.err.println("File not found: "
									+ file.getName());
						} catch (IOException e2) {
							System.err.println("Reading error: "
									+ file.getName());
						}
					}

				}
			});
		}
		return mntmOpen;
	}

	private JMenuItem getMntmSave() {
		if (mntmSave == null) {
			mntmSave = new JMenuItem("Save");
			// Save 액션 리스너
			mntmSave.addActionListener(new ActionListener() {
				public void actionPerformed(ActionEvent e) {
					if (file != null) {
						try {
							// 파일아웃풋스트림에 file+(.txt 메모장으로 저장하기위해) 인스턴스로 전달하여 아웃풋스트림리더의 인스턴스로 전달
							OutputStreamWriter osw = new OutputStreamWriter(
									new FileOutputStream(file + ".txt"));
							String contents = textArea.getText();
							// write 메소드를 통해  osw 버퍼에 내용을 담는다.
							osw.write(contents, 0, contents.length());
							osw.close();
						} catch (FileNotFoundException e1) {
							System.err.println("File not found: "
									+ file.getName());
						} catch (IOException e2) {
							System.err.println("Write error: " + file.getName());
						}
					}
				}
			});
		}
		return mntmSave;
	}

	private JMenuItem getMntmClose() {
		if (mntmClose == null) {
			mntmClose = new JMenuItem("Close");
			// Close 액션 리스너
			mntmClose.addActionListener(new ActionListener() {
				public void actionPerformed(ActionEvent e) {
					// 파일을 없애준다.
					file = null;
					textArea.setText("");
				}
			});
		}
		return mntmClose;
	}

	private JMenuItem getMntmQuit() {
		if (mntmQuit == null) {
			mntmQuit = new JMenuItem("Quit");
			// Quit 액션 리스너
			mntmQuit.addActionListener(new ActionListener() {
				public void actionPerformed(ActionEvent e) {
					//프로그램을 종효시킨다.
					System.exit(0);
				}
			});
		}
		return mntmQuit;
	}

	private JMenuItem getMntmAboutTextEditor() {
		if (mntmAboutTextEditor == null) {
			mntmAboutTextEditor = new JMenuItem("About Text Editor");
			// About Text Editr 액션 리스너
			mntmAboutTextEditor.addActionListener(new ActionListener() {
				public void actionPerformed(ActionEvent e) {
					// 대화상자를 보여준다.
					JOptionPane.showMessageDialog(contentPane, "Text Editor");
				}
			});
		}
		return mntmAboutTextEditor;
	}
}
