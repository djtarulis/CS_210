import re
import string

def printMenu():    # Function to display menu for user
    print("1: Display a Multiplacation Table")
    print("2: Double a Value")
    print("3: Exit")

def MultiplicationTable(v): # Function to display a multiplication table

    for i in range(10): # Loop that iterates from 1 to 10
        print(v, " * ", (i + 1), " = ", v * (i + 1))  
        print()

def DoubleValue(v): # Function to multiply by 2
    return v * 2 
    



    
