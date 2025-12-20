import json
import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

# Load both JSON files
with open("pred.json") as f1:
    data1 = json.load(f1)
with open("pred1.json") as f2:
    data2 = json.load(f2)

frames1 = data1["frames"]
frames2 = data2["frames"]

# Ensure both have the same number of frames for animation
n_frames = max(len(frames1), len(frames2))

fig, (ax1, ax2) = plt.subplots(2, 1, figsize=(8, 6))

# True curve for reference
x_true = np.linspace(0, 2*np.pi, 200)
ax1.plot(x_true, np.sin(x_true), 'k--', label="true sin(x)")
ax2.plot(x_true, np.sin(x_true), 'k--', label="true sin(x)")

# Prediction lines
pred_line1, = ax1.plot([], [], 'b', label="prediction 1")
pred_line2, = ax2.plot([], [], 'r', label="prediction 2")

ax1.legend()
ax2.legend()

ax1.set_xlim(0, 2*np.pi)
ax1.set_ylim(-1.5, 1.5)
ax2.set_xlim(0, 2*np.pi)
ax2.set_ylim(-1.5, 1.5)

def update(frame):
    # Frame for first JSON
    if frame < len(frames1):
        pts1 = frames1[frame]
        x1 = [p["x"] for p in pts1]
        y1 = [p["y"] for p in pts1]
        pred_line1.set_data(x1, y1)
        ax1.set_title(f"Frame {frame} - JSON 1")
    
    # Frame for second JSON
    if frame < len(frames2):
        pts2 = frames2[frame]
        x2 = [p["x"] for p in pts2]
        y2 = [p["y"] for p in pts2]
        pred_line2.set_data(x2, y2)
        ax2.set_title(f"Frame {frame} - JSON 2")
    
    return pred_line1, pred_line2

ani = FuncAnimation(fig, update, frames=n_frames, interval=200)
plt.tight_layout()
plt.show()
