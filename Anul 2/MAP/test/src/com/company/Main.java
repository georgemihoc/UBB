package com.company;

import java.util.*;
import javax.mail.*;
import javax.mail.internet.*;

public class Main
{
    public static void main(String[] args) {
        sendEmailToGmailAccount();
    }

    private static void sendEmailToGmailAccount() {

        try {

            InternetAddress[] distributionList = InternetAddress.parse("javahonk@gmail.com",false);
            String from = "javahonk@gmail.com";
            String subject = "Test email";

            Properties props = new Properties();
            props.put("mail.smtp.host", "localhost");
            props.put("mail.smtp.port", "25");
            Session session = Session.getDefaultInstance(props, null);
            session.setDebug(false);

            Message msg = new MimeMessage(session);
            String message = "bosssss";
            msg.setContent(message, "text/html; charset=utf-8");
            msg.setFrom(new InternetAddress(from));
            msg.setRecipients(Message.RecipientType.TO, distributionList);
            msg.setSubject(subject);
            msg.setSentDate(new Date());
            Transport.send(msg);

        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }
}