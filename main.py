import pygame
import random
import sys
import time
import Wrapper

# CONSTANTS
WIDTH, HEIGHT = 2560, 1340
BAR_WIDTH = 4
NUM_BARS = WIDTH // BAR_WIDTH
WHITE = (255, 255, 255)
RED = (255, 0, 0)
GRAY = (40, 40, 40)

def draw_bars(screen, data, highlight_indicies=None):
    screen.fill(GRAY)
    for i, val in enumerate(data):
        color = RED if highlight_indicies and i in highlight_indicies else WHITE
        pygame.draw.rect(screen, color, (i * BAR_WIDTH, HEIGHT - val, BAR_WIDTH, val))
    pygame.display.flip()


def main():
    # Pygame Initialization
    pygame.init()
    screen = pygame.display.set_mode((WIDTH, HEIGHT))
    pygame.display.set_caption("Sort Visualizer")
    clock = pygame.time.Clock()

    # Data Initialization
    data = [random.randint(10, HEIGHT) for _ in range(NUM_BARS)]
    sorter = Wrapper.QuickSortWrapper(data)

    # Main Loop
    running = True
    while running:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
                break
        still_sorting = sorter.step()
        draw_bars(screen, sorter.get_array())
        pygame.display.flip()
        clock.tick(2**11)

        if not still_sorting:
            break
    input()
    sorter.cleanup()
    pygame.quit()
    sys.exit()

if __name__ == "__main__":
    main()