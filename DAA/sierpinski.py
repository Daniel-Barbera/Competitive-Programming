import numpy as np
import matplotlib.pyplot as plt
from matplotlib.patches import Polygon


def get_midpoint(p1, p2):
    return [(p1[0] + p2[0]) / 2, (p1[1] + p2[1]) / 2]


def draw_sierpinski_triangle(ax, vertices, level):
    if level > 0:
        # Draw triangle
        ax.add_patch(Polygon(vertices, fill = False, edgecolor = (0, 0, 0), linewidth = 0.5))

        # Reference points
        left_vertex = vertices[0]
        top_vertex = vertices[1]
        right_vertex = vertices[2]
        left_edge_midpoint = get_midpoint(left_vertex, top_vertex)
        bottom_edge_midpoint = get_midpoint(left_vertex, right_vertex)
        right_edge_midpoint = get_midpoint(right_vertex, top_vertex)

        # Top triangle
        vertices = np.array([left_edge_midpoint, top_vertex, right_edge_midpoint])
        draw_sierpinski_triangle(ax, vertices, level - 1)
        # Bottom left triangle
        vertices = np.array([left_vertex, left_edge_midpoint, bottom_edge_midpoint])
        draw_sierpinski_triangle(ax, vertices, level - 1)
        # Bottom right triangle
        vertices = np.array([bottom_edge_midpoint, right_edge_midpoint, right_vertex])
        draw_sierpinski_triangle(ax, vertices, level - 1)


def main():
    fig = plt.figure()
    fig.patch.set_facecolor('white')
    ax = plt.gca()
    # Coordinates of a particular equilateral triangle from the unit circle
    vertices = np.array([[-0.866, -0.5], [0.0, 1.0], [0.866, -0.5]])
    draw_sierpinski_triangle(ax, vertices, 7)
    plt.axis('equal')
    plt.axis('off')
    plt.show()

if __name__ == '__main__':
    main()