//Matthew Sliman

public class CaesarCipher {

    public static void main(String[] args){
        
        //program works for lowercase
        String pass = "FAKF KAFWKAFAZ";
        int shift = 2;
        
        System.out.println("Unencrypted text: " + pass);
        String eT = encrypt(pass, shift);
        System.out.println("Encrypted text: " + eT);
        String dT = decrypt(eT, shift);
        System.out.println("Decrypted text: " +dT);
    }
    
    public static String encrypt(String text, int shift) {
        
        String encryptedText = "";
        
        while(shift >= 26)
            shift -= 26;
            
        for(int n = 0; n < text.length(); ++n)
        {
            
            int letterASCII = (int)text.charAt(n);
            
            if(letterASCII == 32)
                encryptedText += " ";
            else if(letterASCII + shift > 90)
                encryptedText += (char)((letterASCII + shift) - 26);
            else
                encryptedText += (char)((int)(text.charAt(n)) + shift);
        }
        
        return encryptedText; 
    }

    // Method to decrypt a text that was encrypted using Caesar Cipher with a specified shift value
    // Precondition: The input text is all uppercase letters and spaces, with no special characters.
    public static String decrypt(String text, int shift) {
        
        String decryptedText = "";
        
        while(shift >= 26)
            shift -= 26;
            
        for(int n = 0; n < text.length(); ++n)
        {
            int letterASCII = (int)text.charAt(n);
            
            if(letterASCII == 32)
                decryptedText += " ";
            else if(letterASCII - shift < 65)
                decryptedText += (char)((letterASCII - shift) + 26);
            else
                decryptedText += (char)(letterASCII - shift);

        }
        
        return decryptedText; 
    }
    
    // Optional: Method to perform brute force decryption by trying all possible shift values
    public static void decryptBruteForce(String text) {
        // Print all possible plaintexts here
        
    }
}
