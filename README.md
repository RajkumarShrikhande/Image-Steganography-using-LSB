# Image steganography using LSB 

Steganography is the art of hiding the fact that communication is taking place, by hiding information in other information. Many carrier file formats can be used, but digital images are the most popular because of their frequency on the internet. For hiding secret information in images, there exists a large variety of steganography techniques some are more complex than others and all of them have respective strong and weak points. Different applications may require absolute invisibility of the secret information, while others require a large secret message to be hidden.Steganography is the practice of hiding private or sensitive information within something that appears to be nothing out of the usual. Steganography is often confused with cryptology because the two are similar in the way that they both are used to protect important information. The difference between two is that steganography involves hiding information so it appears that no information is hidden at all. If a person or persons views the object that the information is hidden inside he or she will have no idea that there is any hidden information, therefore the person will not attempt to decrypt the information.What steganography essentially does is exploit human perception, human senses are not trained to look for files that have information inside them, although this software is available that can do what is called Steganography. The most common use of steganography is to hide a file inside another file.

# Requirement Details
- The application accepts an image file say .bmp along with a text file that contains the message to be steged.
- Analyze the size of the message file to check whether the message could fit in the provided .bmp image.
- Provide an option to steg a magic string which could be useful to identify whether the image is steged or not.
- The application should provide an option to decrypt the file.
- This has to be a command-line application and all the options have to be passed as a command-line argument.

# Compile all the C files using:
    gcc -W all *.c
    
- You can create a makefile to build this project if you want
# For Encoding, 
- You have to use -e followed by an input image filename followed by a secret filename.
  (Note that these files must be present in the current project directory, otherwise an error message appears. Also note that the input image filename must be having ".bmp" format to avoid error while the secret file can be of any format: .c, .cpp, .txt, .vhdl etc. But the format type cannot exceed more than 4 characters because a macro MAX_FILE_SUFFIX has been set to 4. Also don't miss the dot in any filename. It will result in an error).
# Use following commands
          ./a.out -e beautiful.bmp secret.txt

- The above input will generate an additional image file in the project directory namely "stego.bmp" which is default output filename.
- You can provide your own output filename by giving 4th argument as shown below:
- (Note that this filename must be having ".bmp" format, otherwise an error message will be shown)
          ./a.out -e beautiful.bmp secret.txt my_stegged_img.bmp

- If you want to incorporate more security, you can use a passcode for encrypting operation using -p followed by the passcode.
- Example -  ./a.out -e beautiful.bmp secret.txt my_stegged_img.bmp -p 123
- (Note that the passcode can contain maximum 4 "digits". You cannot use a passcode like: 1$3q)
- The output image file looks exactly like the input image file. To decrypt the message inside it, use the decrypting technique.

# For Decoding
- you have to use -d followed by output image filename.
# Use following commands
          ./a.out -d stego.bmp decode.txt

- It will decrypt the secret message from the image and store it in a newly created file called "decode.txt" which is default decoded filename. This file has the same format as that of the input secret file format.
- If you want to provide your own decoded filename, you can do so by using 3rd argument as shown below:
          ./a.out -d stego.bmp decode.txt

- (Note that the file format must match with that of the input secret file's format. Otherwise an error message appears)

- If a passcode is used while encrypting, the above input results in an error.
- Now user has to provide the correct passcode as shown below:
          ./a.out -d stego.bmp my_decoded_file.txt -p 123

- In both operations, you can provide the filename by its path like: Projects/Steganography/beautiful.bmp (But the files must be in the same project directory)
- Example -  ./a.out -e Projects/Steganography/beautiful.bmp Projects/Steganography/secret.txt
- But the file has to be present in your current project directory.
          ./a.out -d stego.bmp decode.txt
- This will create output file as decode.txt.
