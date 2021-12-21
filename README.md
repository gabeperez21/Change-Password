# Change-Password

### WARNING: This program will save the password inputted into a .dat file in your computer. The password saved will NOT be encrypted NOR hashed. Please DO NOT store any real passwords in this program or in the .dat as it can be compromised.

This program will attempt to read a file named "Already Used Passwords.dat". If the file is not found in the same folder that contains the .exe, the program will shut down. 

If the file is found, you will be able to enter a new password. The new password needs to meet certain requirements before it is accepted. The password needs to have a certain amount of uppercase letters, lowercase letters, digits, and special characters. The password also needs to be unique.

If the password entered is valid, the program will read from the file to see if it has been used before. If it has been used before, the program will not accept the password and will display an error. If the password is accepted, a message will appear and the new password will be saved into the "Already Used Passwords.dat" file.
