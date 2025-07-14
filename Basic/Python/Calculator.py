# Calculator program
# A basic arithmetic program

# Arithmetic functions:
def Addition(num1,num2):
    return num1 + num2

def Subtraction(num1, num2):
    return num1 - num2

def Division(num1, num2):
    return num1 / num2

def Multiplication(num1, num2):
    return num1 * num2

def Exponents(num1,num2):
     return num1 ** num2

def Pythagoras(num1, num2):
     return ((num1**2) + (num2**2)) **0.5

def Pi(num1):
     return 3.142 * (num1 **2)

# Main function:
def main():
    while True:
        print('\nThis performs arithmetic functions')
        print('Please select from one of the following:')
        print('1. Addition')
        print('2. Subtraction')
        print('3. Division')
        print('4. Multiplication')
        print('5. Exponents')
        print('6. Pythagoris')
        print('7. Pi')
        print('8. Exit')

        # Obtaining response and exiting if non int entered
        try:
            response = int(input('Enter the number of the calculation:\n'))
        except ValueError:
            continue
    
        # Exiting the programming before doing anthing else:
        if response == 8:
            print('You selected to exit')
            print('Ending program')
            break
         
        # Get numbers if you chose not to exit:
        if response in {1,2,3,4,5,6}:
            num1 = int(input('Enter the first number:\n'))
            num2 = int(input('Enter the second number:\n'))
        elif response == 7:
            num1 = int(input('Enter in a number:\n'))
    
        # Performing calculations
        if response == 1:
            print(f'You selected Addition: {num1} + {num2} equals {Addition(num1,num2)}')
        elif response == 2:
            print(f'You selected Subtraction: {num1} - {num2} equals {Subtraction(num1, num2)}')
        elif response == 3:
            if num2 != 0:
                print(f'You selected Division: {num1} / {num2} equals {Division(num1, num2)}')
            else:
                print('Error: Division by zero is not allowed')
        elif response == 4:
            print(f'You selected Multiplication: {num1} and {num2} equals {Multiplication(num1, num2)}')
        elif response == 5:
            print(f'You selected Exponents: {num1} and {num2} equals {Exponents(num1, num2)}')
        elif response == 6:
            print(f'You selected Pythagoras: {num1} and {num2} equals: {Pythagoras(num1,num2)}')
        elif response == 7:
            print(f'You selected Pi: {num1} equals {Pi(num1)}')
        else:
            continue
        rerun = input('Do you wish to continue: Yes or no\n')
        rerun = rerun.lower()
        if rerun != 'yes':
            print('You chose not to rerun calculaor')
            break
  
# Running the main function:          
if __name__ == '__main__':
        main()


                     
