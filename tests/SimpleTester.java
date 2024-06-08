import java.io.BufferedWriter;
import java.io.IOException;
import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.io.OutputStreamWriter;
import java.util.Calendar;
import javax.xml.parsers.ParserConfigurationException;
import javax.xml.parsers.SAXParser;
import javax.xml.parsers.SAXParserFactory;

import org.xml.sax.Attributes;
import org.xml.sax.SAXException;
import org.xml.sax.helpers.DefaultHandler;

public class SimpleTester extends DefaultHandler {

   private String temp;
   
   /** The main method sets things up for parsing */
   public static void main(String[] args) throws IOException, SAXException, java.io.FileNotFoundException, ParserConfigurationException {
      
      //Create a "parser factory" for creating SAX parsers
      SAXParserFactory spfac = SAXParserFactory.newInstance();
      
      //Now use the parser factory to create a SAXParser object
      SAXParser sp = spfac.newSAXParser();
      
      //Create an instance of this class; it defines all the handler methods
      SimpleTester handler = new SimpleTester();
      
      //Finally, tell the parser to parse the input and notify the handler
      try {
         sp.parse(args[0], handler);
      } catch (Exception fnfe) {
         System.out.println("tried to parse " + args[0] + ". error: " + fnfe.getMessage());
      }
      File myFile = new File(args[0]);
      System.out.println(myFile.getAbsolutePath() + " was last modified " + myFile.lastModified());
      Calendar fileCalendar = Calendar.getInstance();
      fileCalendar.setTimeInMillis(myFile.lastModified());
      System.out.println("which means year: " + fileCalendar.get(Calendar.YEAR) + ", month: " + fileCalendar.get(Calendar.MONTH) + ", date: " + fileCalendar.get(Calendar.DAY_OF_MONTH) + ", hour: " + fileCalendar.get(Calendar.HOUR_OF_DAY) + ", minute: " + fileCalendar.get(Calendar.MINUTE) + ", second: " + fileCalendar.get(Calendar.SECOND));
      File file = new File("/tmp/bestofjava/java_time.txt");
 
      // if file doesnt exists, then create it
      if (!file.exists()) {
         file.createNewFile();
      }
 
      FileWriter fw = new FileWriter(file.getAbsoluteFile());
      BufferedWriter bw = new BufferedWriter(fw);
      bw.write(Long.toString(System.currentTimeMillis()));
      bw.newLine();
      Calendar oldCal=Calendar.getInstance(),newCal=Calendar.getInstance();
      
      if (myFile.exists()) System.out.println("oh yes, " + myFile.getName() + " exists");
      else System.out.println("crap, " + myFile.getName() + " does not exist");
      System.out.println("the absolute path is " + myFile.getAbsolutePath());
      System.out.println("the parent dir is " + myFile.getParent());
      File parentDir = new File(myFile.getParent());
      if (parentDir.isDirectory()) System.out.println(parentDir.getAbsolutePath() + " is a directory");
      else System.out.println(parentDir.getAbsolutePath() + " is not a directory");
      oldCal.setTimeInMillis(myFile.lastModified());
      newCal.setTimeInMillis(System.currentTimeMillis());
      if (oldCal.after(newCal)) System.out.println("oups, " + oldCal.getTimeInMillis() + " is after " + newCal.getTimeInMillis());
      if (newCal.before(oldCal)) System.out.println("oups, " + newCal.getTimeInMillis() + " is before " + oldCal.getTimeInMillis());
      Calendar getset = Calendar.getInstance();
      getset.set(2014, 3, 5);
      bw.write(Long.toString(getset.getTimeInMillis())); //2014-04-05 in millis
      bw.close();
      System.out.println("year: " + getset.get(Calendar.YEAR) + ", month: " + getset.get(Calendar.MONTH) + ", date: " + getset.get(Calendar.DAY_OF_MONTH));
      getset.setTimeInMillis(getset.getTimeInMillis());
      PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
      pw.println("after calendar time is reset in millis: year: " + getset.get(Calendar.YEAR) + ", month: " + getset.get(Calendar.MONTH) + ", date: " + getset.get(Calendar.DAY_OF_MONTH));
      pw.flush();
      pw.close();
   }


   /*
    * When the parser encounters plain text (not XML elements),
    * it calls(this method, which accumulates them in a string buffer
    */
   public void characters(char[] buffer, int start, int length) {
      temp += new String(buffer, start, length);
   }
   

   /*
    * Every time the parser encounters the beginning of a new element,
    * it calls this method, which resets the string buffer
    */ 
   public void startElement(String uri, String localName, String qName, Attributes attributes) throws SAXException {
      temp = "";
      System.out.print("<" + qName + ">");
      if (!uri.equals("")) System.out.print("uri: " + uri + " ");
      if (!localName.equals("")) System.out.print("localName: " + localName + " ");
//   for(int i=0; i < attributes.getLength(); i++)
      //  System.out.print(attributes.getQName(i) + " has type " + attributes.getType(i) + " ");
   }
   
   /*
    * When the parser encounters the end of an element, it calls this method
    */
   public void endElement(String uri, String localName, String qName)
                     throws SAXException {
      if (!uri.equals("")) System.out.print("uri: " + uri + " ");
      if (!localName.equals("")) System.out.print("localName: " + localName + " ");
      if (!temp.equals("")) System.out.print("characters: " + temp);
      System.out.println("</" + qName + ">");
   }
   
   
   
}
