import cv2
import numpy as np

# Parameters
color = (94, 255, 234)  # BGR format (red)
duration = 60         # seconds (1 minute)
fps = 30
size = (500, 500)    # width, height

# Heartbeat parameters
base_interval = 2.2    # initial interval between beats (slightly slower for calming effect)
slowing_factor = 1.02  # slower gradual slowing
pulse_length = 1.2     # seconds pulse is fully bright

# Video writer
fourcc = cv2.VideoWriter_fourcc(*'mp4v')
out = cv2.VideoWriter('heartbeat_opencv.mp4', fourcc, fps, size)

frame_count = int(duration * fps)
next_beat = 0
interval = base_interval

for i in range(frame_count):
    t = i / fps

    # Determine brightness
    if t >= next_beat:
        # Start new pulse
        pulse_start = next_beat
        next_beat += interval
        interval *= slowing_factor

    # Smooth pulse: brightness rises and falls
    dt = t - pulse_start if 'pulse_start' in locals() else 0
    if 0 <= dt < pulse_length:
        brightness = 1 - (dt / pulse_length)  # fade out during pulse
    else:
        brightness = 0

    # Fade out over entire duration for calming effect
    fade = max(0, 1 - t / duration)
    brightness *= fade

    # Create frame
    frame_color = tuple(int(c * brightness) for c in color)
    frame = np.full((size[1], size[0], 3), frame_color, dtype=np.uint8)

    out.write(frame)

out.release()
cv2.destroyAllWindows()
print("Video created: heartbeat_opencv.mp4")
