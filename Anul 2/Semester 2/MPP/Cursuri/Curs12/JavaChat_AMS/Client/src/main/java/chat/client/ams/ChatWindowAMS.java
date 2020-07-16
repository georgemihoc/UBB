package chat.client.ams;

import chat.client.gui.ChatClientCtrl;
import chat.services.ChatException;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

/**
 * Created by IntelliJ IDEA.
 * User: grigo
 * Date: Mar 18, 2009
 * Time: 2:52:27 PM
 */
public class ChatWindowAMS extends JFrame{
    private JList friendsList, messagesList;
    private JTextField message;
    private JButton sendButt, sendAllBut;
    private ChatClientCtrlAMS ctrl;
    public ChatWindowAMS(String title, ChatClientCtrlAMS ctrl){
        super(title);
        this.ctrl=ctrl;
        JPanel panel=new JPanel(new BorderLayout());

        panel.add(createSendMessage(), BorderLayout.SOUTH);
        panel.add(createMessages(), BorderLayout.WEST);
        panel.add(createFriends(), BorderLayout.CENTER);
        getContentPane().add(panel);
        addWindowListener(new WindowAdapter(){
            public void windowClosing(WindowEvent e){
                close();
            }
        });
    }

    private void close(){
         ctrl.logout();
    }

    private JPanel createFriends(){
        JPanel res=new JPanel(new GridLayout(1,1));
        friendsList=new JList(ctrl.getFriendsModel());
        JScrollPane scroll=new JScrollPane(friendsList);
        res.add(scroll);
        res.setBorder(BorderFactory.createTitledBorder("Logged in users"));
        return res;
    }
     private JPanel createMessages(){
        JPanel res=new JPanel(new GridLayout(1,1));
        messagesList=new JList(ctrl.getMessagesModel());
        JScrollPane scroll=new JScrollPane(messagesList);
        res.add(scroll);
        res.setBorder(BorderFactory.createTitledBorder("Messages"));
        return res;
    }

    private JPanel createSendMessage(){
        JPanel res=new JPanel(new GridLayout(2,1));
        JPanel line1=new JPanel();
        line1.add(new JLabel("Message "));
        line1.add(message = new JTextField(30));
        res.add(line1);
        JPanel line2=new JPanel();
       // line2.add(sendButt=new JButton("Send message"));
   //     sendButt.addActionListener(new ButListener());
        line2.add(sendAllBut=new JButton("Send all users"));
        sendAllBut.addActionListener(new SendAllListener());
        res.add(line2);
        return res;
    }



    private class SendAllListener implements ActionListener {

        public void actionPerformed(ActionEvent e) {
            System.out.println("Send all button pressed");
            String txtMsg=message.getText();
            if ("".equals(txtMsg.trim())) {
                JOptionPane.showMessageDialog(ChatWindowAMS.this, "You must enter the message", "Send error", JOptionPane.ERROR_MESSAGE);
                return;
            }
            try {
                ctrl.sendMessageToAll(txtMsg);
            } catch (ChatException e1) {
                JOptionPane.showMessageDialog(ChatWindowAMS.this, "Error "+e1, "Send error", JOptionPane.ERROR_MESSAGE);
                return;
            }




        }
    }

}
