import numpy
import pyaudio
import pygame
import random
import sys
import time
import Wrapper

# CONSTANTS
WIDTH, HEIGHT = 2560, 1440
BAR_WIDTH = 1
NUM_BARS = WIDTH // BAR_WIDTH
WHITE = (255, 255, 255)
RED = (255, 0, 0)
GRAY = (40, 40, 40)

class AudioPlayer:
    def __init__(self):
        self.p = pyaudio.PyAudio()
        self.stream = self.p.open(
            format=pyaudio.paInt16,
            channels=1,
            rate=44100,
            output=True
        )
    
    def play_tone(self, frequency=440, duration_ms=30, volume=0.5):
        fs = 44100
        t = numpy.linspace(0, duration_ms / 1000.0, int(fs * duration_ms / 1000.0), False)
        tone = numpy.sin(2 * numpy.pi * frequency * t) * volume
        audio = (tone * 32767).astype(numpy.int16).tobytes()
        self.stream.write(audio)

    def cleanup(self):
        self.stream.stop_stream()
        self.stream.close()
        self.p.terminate()

def draw_bars(screen, data, highlight_indices=None):
    screen.fill(GRAY)
    for i, val in enumerate(data):
        color = RED if highlight_indices and i in highlight_indices else WHITE
        pygame.draw.rect(screen, color, (i * BAR_WIDTH, HEIGHT - val, BAR_WIDTH, val))


def main():
    # Pygame Initialization
    pygame.init()
    pygame.font.init()
    display_font = pygame.font.SysFont('Rubik', 128)
    sorted_text = display_font.render("Sorted", True, RED, WHITE)
    sorted_text_rect = sorted_text.get_rect()
    sorted_text_rect.center = (WIDTH / 2, 100)
    screen = pygame.display.set_mode((WIDTH, HEIGHT))
    pygame.display.set_caption("Sort Visualizer")
    clock = pygame.time.Clock()

    # Audio Initialization
    player = AudioPlayer()

    # Data Initialization
    data = [random.randint(1, HEIGHT) for _ in range(NUM_BARS)]
    insertionSorter = Wrapper.InsertionSortWrapper(data[:])
    selectionSorter = Wrapper.SelectionSortWrapper(data[:])
    bubbleSorter = Wrapper.BubbleSortWrapper(data[:])
    quickSorter = Wrapper.QuickSortWrapper(data[:])
    mergeSorter = Wrapper.MergeSortWrapper(data[:])
    radixSorter = Wrapper.RadixSortWrapper(data[:])
    countingSorter = Wrapper.CountingSortWrapper(data[:])
    sorters = {
        "Insertion Sort":insertionSorter,
        "Selection Sort":selectionSorter,
        "Bubble Sort":bubbleSorter,
        "Quick Sort":quickSorter,
        "Merge Sort":mergeSorter,
        "Radix Sort":radixSorter,
        "Counting Sort":countingSorter
    }
    
    welcome_text = display_font.render("WELCOME", True, RED, WHITE)
    welcome_text_rect = welcome_text.get_rect()
    welcome_text_rect.center = (WIDTH / 2, HEIGHT / 2)
    running = True
    
    dummy_data = [random.randint(1, HEIGHT) for _ in range(NUM_BARS)]
    count = 0
    while running:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
                break
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_ESCAPE:
                    running = False
                    break
        count += 1
        if count > 300:
            dummy_data = [random.randint(1, HEIGHT) for _ in range(NUM_BARS)]
            count = 0
        draw_bars(screen, dummy_data)
        screen.blit(welcome_text, welcome_text_rect)
        pygame.display.flip()
    for name, sorter in sorters.items():
        # Main Loop
        name_text = display_font.render(name, True, RED, WHITE)
        name_text_rect = name_text.get_rect()
        name_text_rect.center = (WIDTH / 2, 100)
        running = True
        count = 0
        while running:
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    running = False
                    break
                if event.type == pygame.KEYDOWN:
                    if event.key == pygame.K_ESCAPE:
                        running = False
                        break
            if count > 1000:
                running = False
            count += 1
            screen.blit(name_text, name_text_rect)
            pygame.display.flip()
        running = True
        while running:
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    running = False
                    break
                if event.type == pygame.KEYDOWN:
                    if event.key == pygame.K_ESCAPE:
                        running = False
                        break
            still_sorting = sorter.step()

            highlight_i = sorter.get_highlight_i()
            highlight_j = sorter.get_highlight_j()
            highlight_k = sorter.get_highlight_write()
            highlighters = [i for i in (highlight_i, highlight_j, highlight_k) if 0 <= i < len(sorter.get_array())]
            base_height = sorter.get_sound_data()
            frequency = 200 + base_height/HEIGHT * 1000
            player.play_tone(frequency=frequency, duration_ms=30)

            draw_bars(screen, sorter.get_array(), highlighters)
            pygame.display.flip()
            clock.tick(0)

            running = running and still_sorting

        running = True
        count = 0
        while running:
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    running = False
                    break
                if event.type == pygame.KEYDOWN:
                    if event.key == pygame.K_ESCAPE:
                        running = False
                        break
            if count > 100:
                running = False
            count += 1
            draw_bars(screen, sorter.get_array(), highlighters)
            screen.blit(sorted_text, sorted_text_rect)
            pygame.display.flip()
        sorter.cleanup()
    player.cleanup()
    pygame.quit()
    sys.exit()

if __name__ == "__main__":
    main()