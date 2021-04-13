from graph import *
import random as rand

#Starts graph
start_node = node(rand.randint(0,100),rand.randint(0,100))
my_graph = graph(start_node)

#Fills graph
for i in range(4):
    random_x = rand.randint(0,100)
    random_y = rand.randint(0,100)

    my_graph.add_node(random_x, random_y)

search_space = len(my_graph.all_nodes) - 1
temp1 = my_graph.all_nodes[rand.randint(0,search_space)]
temp2 = my_graph.all_nodes[rand.randint(0,search_space)]
my_graph.add_connection(temp1,temp2)

my_graph.show_nodes()
my_graph.show_matrix()