import java.io.BufferedWriter;
import java.io.IOException;
import java.io.File;
import java.io.FileWriter;
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
      System.out.println(args[0] + " was last modified " + new File(args[0]).lastModified());

      File file = new File("/tmp/bestofjava/java_time.txt");
 
      // if file doesnt exists, then create it
      if (!file.exists()) {
         file.createNewFile();
      }
 
      FileWriter fw = new FileWriter(file.getAbsoluteFile());
      BufferedWriter bw = new BufferedWriter(fw);
      bw.write(new Long(System.currentTimeMillis()).toString());
      bw.close();
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
      //  for(int i=0; i < attributes.getLength(); i++)
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
