#!/usr/bin/python3
import random
import os

characters = ['1', '2', '3', '4', '5', '6', '7', '8', '9', '0','q','w','e','r','t','y','u','i','o','p','a','s','d','f','g','h','j','k','l','z','x','c','v','b','n','m','!','@','#','$','%','^','&','*','(',')','-','_','=','+','`','~','[',']',';']

password = ""

os.system('cls' if os.name == 'nt' else 'clear')

print("""
        Select power of u password

        1. Low (64 characters)
        2. Medium (128characters)
        3. High (512 characters)
        4. Strong (1024 characters)
        5. Ultra (2048 characters)

        """)
option = 0

while option == 0:
    try:
        ppower = int(input())
        if ppower == 1:
            option = 64
        elif ppower == 2:
            option = 128
        elif ppower == 3:
            option = 512
        elif ppower == 4:
            option = 1024
        elif ppower == 5:
            option = 2048
        else:
            print("Insert number between 1-5")
    except:
        print("Insert number between 1-5")


for i in range(option):
    
    nchar = random.randint(0, len(characters)-1)
    char = characters[nchar]
    password += char

print("\nPassword:\n"+password+"\n")

ans = input("Can u save this password to file?   (y/n): ")
if ans == "y":
    note = input("If you want u can add note for ur password or leave it blank (example: pass to my mail): ")

    passFile = open('passwords.txt', 'a+')
    try:
        oldPass = passFile.read()
        passFile.write(oldPass+ "\n\n" + note + ": " + password + "\n")
    except:
        passFile.write(note + ": " + password + "\n")
    passFile.close()
