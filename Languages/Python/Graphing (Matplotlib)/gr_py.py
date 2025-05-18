import matplotlib.pyplot as plt
import seaborn as sns
import numpy as np

#scatter plot
def scatter_plot():
#using sample data from an ice cream company to study the growth in the sale of ice creams against varying temperature data.
    temperature = [14.2, 16.4, 11.9, 12.5, 18.9, 22.1, 19.4, 23.1, 25.4, 18.1, 22.6, 17.2]
    sales = [215.20, 325.00, 185.20, 330.20, 418.60, 520.25, 412.20, 614.60, 544.80, 421.40, 445.50, 408.10]
    plt.title('Ice-cream sales versus Temperature')
    plt.xlabel('Sales')
    plt.ylabel('Temperature')
    plt.scatter(temperature, sales, color='red')#creates a scatter plot
    plt.show()#displays the graph

#line chart    
def line_chart():   
    stock_price = [190.64, 190.09, 192.25, 191.79, 194.45, 
                196.45, 196.45,196.42, 200.32, 200.32, 200.85, 199.2,
                199.2, 199.2, 199.46, 201.46, 197.54, 201.12, 203.12,
                203.12, 203.12, 202.83, 202.83, 203.36, 206.83, 204.9,
                204.9, 204.9, 204.4, 204.06]
    days = list((range(1, 31))) #x axis
    plt.title('Opening Stock Prices')
    plt.xlabel('Days')
    plt.ylabel('$ USD')
    
    plt.plot(days, stock_price, marker='.', color='red')
    plt.xticks([1, 6, 16, 20, 28]) #defines numbers on the x axis
    plt.show()

#bar plots: A bar plot is a straightforward chart type. It is great for visualizing the count of items in different categories.
def bar_plot():
    grades = ['A', 'B', 'C', 'D', 'E', 'F']
    students_count = [20, 30, 10, 5, 8, 2]
    plt.title('Grades Bar Plot for Biology Class')
    plt.xlabel('Grade')
    plt.ylabel('Num Students')
    plt.bar(grades, students_count, color=['green', 'gray', 'gray', 'gray', 'gray', 'red']) #.barh would make the graph horizontal
    plt.show()
    
#pie chart: good for visualizing percentages and fractional data.
def pie_chart():
    # Plotting
    labels = ['Monica', 'Adrian', 'Jared']
    num = [230, 100, 98] # Note that this does not need to be percentages
    plt.title('Voting Results: Club President',fontdict={'fontsize': 120})
    plt.pie(num, labels=labels, autopct='%1.1f%%', colors=['lightblue', 'lightgreen', 'yellow'])
    plt.show()

#density plot: 
def density_plot():
    data = [90, 80, 50, 42, 89, 78, 34, 70, 67, 73, 74, 80,60, 90, 90]
    plt.title('Density Plot')
    plt.xlabel('Score')
    plt.ylabel('Density')
    sns.distplot(data) #.displot used to plot the data as a density plot.
    plt.show()
    
#contour plots:  are suitable for visualizing large and continuous datasets; like a density plot with two features.
def contour_plots():
    weight = [85.08,79.25,85.38,82.64,80.51,77.48,79.25,78.75,77.21,73.11,82.03,82.54,74.62,79.82,79.78,77.94,83.43,73.71,80.23,78.27,78.25,80.00,76.21,86.65,78.22,78.51,79.60,83.88,77.68,78.92,79.06,85.30,82.41,79.70,80.16,81.11,79.58,77.42,75.82,74.09,78.31,83.17,75.20,76.14]
    height = list(range(1,45))
    plt.legend(labels=['a', 'b'])
    plt.title('Weight Dataset - Contour Plot')
    plt.ylabel('height (cm)')
    plt.xlabel('width (cm)')
    #kdeplot() automatically handles the density plot.
    sns.kdeplot(x=height, y=weight, cmap="Reds", fill=False)  # Create a contour plot
    plt.show()

#extending graphs 
#show multiple charts in the same figure for comparison purposes or to
#extend the depth of the story that you are telling. For instance, in an election, you want one chart that
#shows the percentage, and another chart that shows the actual votes
def extending_plots():
    # Split the figure into 2 subplots
    fig = plt.figure(figsize=(8,4))
    ax1 = fig.add_subplot(121) # 121 means split into 1 row ,2 columns, and put in 1st part.
    ax2 = fig.add_subplot(122) # 122 means split into 1 row ,2 columns, and put in 2nd part.
    #plots the first subplot, which is a pie chart
    labels = ['Adrian', 'Monica', 'Jared']
    num = [230, 100, 98] 
    ax1.pie(num, labels=labels, autopct='%1.1f%%', colors=['lightblue', 'lightgreen','yellow'])
    ax1.set_title('Pie Chart (Subplot 1)')
    #the second subplot, which is a bar chart
    labels = ['Adrian', 'Monica', 'Jared']
    num = [230, 100, 98]
    plt.bar(labels, num, color=['lightblue', 'lightgreen','yellow'])
    ax2.set_title('Bar Chart (Subplot 2)')
    ax2.set_xlabel('Candidate')
    ax2.set_ylabel('Votes')
    fig.suptitle('Voting Results', size=14)
    
    plt.show()
 
#3D plot: sine wave using sample data 
def three_d_plot():
    X = np.linspace(0, 10, 50)
    Y = np.linspace(0, 10, 50)
    X, Y = np.meshgrid(X, Y)
    Z = (np.sin(X))
    # Setup axis
    fig = plt.figure(figsize=(7,5))
    ax = fig.add_subplot(111, projection='3d')
    ax.plot_surface(X, Y, Z)
    # Add title and axes labels
    ax.set_title("Demo of 3D Plot", size=13)
    ax.set_xlabel('X')
    ax.set_ylabel('Y')
    ax.set_zlabel('Z')
    plt.show()
    
def main_g():
    three_d_plot()
    

if __name__=="__main__":
    main_g()