class node():
    
    def __init__(self, x, y):
        self.location = [x, y]

class graph():

    #Constructor
    def __init__(self, start):
        self.all_nodes = [start]
        self.adj_mat = [[False]]

    #Returns whether a node is in the graph or not
    def in_graph(self, input):
        
        #Loops through each node in all_nodes
        for node in self.all_nodes:

            #Checks to see if data is the same
            if input.location[0] == node.location[0] and input.location[1] == node.location[1]:
                return True

        return False
    
    #Adds a new node to the graph
    def add_node(self, input_x, input_y):

        #Create a node with input values
        input = node(input_x, input_y)
        #Add node to graph
        self.all_nodes.append(input)

        #Expand each row of the matrix to include the new node
        for i in range(0, len(self.adj_mat)):
            self.adj_mat[i].append(False)

        #Add an additional row to the matrix to include the new node
        temp = []
        for i in range(0, len(self.adj_mat) + 1):
            temp.append(False)
        
        #Add row to matrix
        self.adj_mat.append(temp)
    
    #Adds a connection between two nodes in the graph
    def add_connection(self, first_node, second_node):

        #Determine if the nodes are even in the graph
        if self.in_graph(first_node) and self.in_graph(second_node):

            #Find where nodes are in our all_nodes list
            for i in range(len(self.all_nodes)):

                #If their coord values are the same then we have found it
                if(first_node.location[0] == self.all_nodes[i].location[0] 
                   and first_node.location[1] == self.all_nodes[i].location[1]):
                    pos_one = i

                if(second_node.location[0] == self.all_nodes[i].location[0] 
                   and second_node.location[1] == self.all_nodes[i].location[1]):
                    pos_two = i
            
            self.adj_mat[pos_one][pos_two] = True
            self.adj_mat[pos_two][pos_one] = True

    #Prints out the VALUES of each of the nodes in the graph
    def show_nodes(self):

        for node in self.all_nodes:
            print("(%s,%s)" % (node.location[0], node.location[1]))
    
    #Prints out the adjency matrix
    def show_matrix(self):
        
        for i in range(len(self.adj_mat)):
            for j in range(len(self.adj_mat)):

                print(self.adj_mat[i][j], end=" ")
            print("\n")