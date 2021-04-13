import pygame           #For drawing
import random           #Random
from graph import *     #Graph class
import math             #For the train_lines() example
pygame.init()

# Constants -----------------------------------------------------------------
WIDTH, HEIGHT = 1000, 1000
BLACK = 0,0,0
WHITE = 255,255,255
RED = 255,0,0
line_width = 2
circle_radius = 10

# Window set-up -------------------------------------------------------------
WIN = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Bubble Sort")
FPS = 5
clock = pygame.time.Clock()

#Graph set up ---------------------------------------------------------------
start_node = node(random.randint(0,900), random.randint(0,900))
my_g = graph(start_node)

#Pygame and graphs meet -----------------------------------------------------
#Basic function to draw nodes!
def draw_nodes():

    for node in my_g.all_nodes:
        pygame.draw.circle(WIN, WHITE, (node.location[0], node.location[1]), circle_radius)

#Basic function to draw connections!
def draw_connections():

    #Loop through the adjency matrix
    for i in range(len(my_g.adj_mat)):
        for j in range(len(my_g.adj_mat)):

            #If the value there is true
            if(my_g.adj_mat[i][j]):

                #These two variables store the location 
                #variables of the nodes that are connected
                start = my_g.all_nodes[i].location
                stop = my_g.all_nodes[j].location
                
                #Draw a line between the start and stop
                pygame.draw.line(WIN, WHITE, start, stop, line_width)

def make_connections_and_draw():

    search_space = len(my_g.all_nodes) - 1
    temp_1 = my_g.all_nodes[random.randint(0, search_space)]
    temp_2 = my_g.all_nodes[random.randint(0, search_space)]
    my_g.add_connection(temp_1, temp_2)

    draw_nodes()
    draw_connections()

def make_connections_nodes_and_draw():

    #Make a node
    random_x = random.randint(20, WIDTH - 20)
    random_y = random.randint(20, HEIGHT - 20)
    my_g.add_node(random_x, random_y)

    #Make a connection
    search_space = len(my_g.all_nodes) - 1
    temp_1 = my_g.all_nodes[random.randint(0, search_space)]
    temp_2 = my_g.all_nodes[random.randint(0, search_space)]
    my_g.add_connection(temp_1, temp_2)

    draw_nodes()
    draw_connections()

def train_lines():

    search_space = len(my_g.all_nodes) - 1
    #Make a node
    random_x = random.randint(20, WIDTH - 20)
    random_y = random.randint(20, HEIGHT - 20)
    my_g.add_node(random_x, random_y)
    last_added_node = my_g.all_nodes[search_space]

    #Find the closest existing node
    best_score = 100000
    closest_node = start_node
    for i in range(len(my_g.all_nodes) - 2):
        new_node_x = last_added_node.location[0]
        new_node_y = last_added_node.location[1]
        node_x     = my_g.all_nodes[i].location[0]
        node_y     = my_g.all_nodes[i].location[1]

        distance = math.sqrt( (new_node_x - node_x)**2 + (new_node_y - node_y)**2 )
        if distance < best_score:
            best_score = distance
            closest_node = my_g.all_nodes[i]
    
    my_g.add_connection(last_added_node, closest_node)

    #Draw nodes white, except for our root node
    pygame.draw.circle(WIN, RED, (my_g.all_nodes[0].location[0], my_g.all_nodes[0].location[1]), circle_radius)
    for i in range(1, len(my_g.all_nodes)):
        pygame.draw.circle(WIN, WHITE, (my_g.all_nodes[i].location[0], my_g.all_nodes[i].location[1]), circle_radius)
    draw_connections()

while 1:

    # Capped FPS
    clock.tick(FPS)

    # Resets the screen every tick
    WIN.fill(BLACK)

    # Checks to see if user exits
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            sys.exit()

    train_lines()

    pygame.display.update()