#CLASS EXAMPLE
class human:
    """
    Checks if someone is human.
    """
    def __init__(self, height, first_name='Mike', last_name = 'Johnson', size='big'):#intializes a new instance of a class
        #attributes
        self.height = height
        self.size = size
        self.first_name = first_name
        self.last_name = last_name
    
    @property
    def full_name(self):
        return f'{self.first_name} {self.last_name}'
     
    @full_name.setter
    def full_name(self, name):
        first, last = name.split(' ')
        self.first_name = first
        self.last_name = last
        
    @property
    def height_size(self):
        return f'{self.height} {self.size}'

    def __str__(self): #string output of an object
        return f"{self.first_name} is {self.height} feet tall"
    
    is_human = True
    enjoys_sport = True
    
    #instance method
    def doubled_height(self):
        return 2 * self.height
    
    
    #static method - its results will be same for all object instances
    @staticmethod
    def static_print():
        return "ok ratio"
    #A BETTER ExAMPLE OF THIS IS:
    #@staticmethod
    #def format_date(date): helper function inside a class
        #return date.strftime('%d-%b-%y')
        
    @classmethod
    def create_with_inches(cls, height, name='Mike', size='big'):
        height_inches = height * 12
        return cls(height_inches, name, size)
    
    
def intro_to_class():
    #example of built in class
    my_str = 'hello'
    type(my_str) #shows type
    print(my_str.__doc__)#shows documentation
    print(my_str.__dir__())#full list of properties and methods
    
   #example of created class
    #class method example
    john2 = human.create_with_inches(5)
    #property
    print(john2.full_name)
    print(john2.height_size)
    
    #setter
    marc = human(4)
    marc.full_name = 'Dan Schine'
    print(marc.first_name)
    print(marc.last_name)
    
    #example 1
    john = human(height=5)
    print(john.is_human)
    print(john.height, john.size, john.doubled_height())
    print(john.__str__())
    
def main():
    intro_to_class()

    
if __name__ == "__main__":
    main()