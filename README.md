# 🚦 On-Demand Smart Traffic Light System

An embedded C project simulating a smart traffic light system that gives pedestrians priority when crossing. Developed as part of the Embedded Systems Professional Nanodegree offered by **Egypt FWD** and **Udacity**.

## 🎯 Objective

Reduce waiting time for pedestrians at a crosswalk by interrupting the car traffic cycle when a pedestrian presses a button. The system supports two modes of operation:

### 🔁 Normal Mode
- Traffic lights for cars operate in the standard cycle:  
  **Red → Yellow → Green → Yellow → Red** (loop).

### 🚶‍♂️ Pedestrian Mode
- Triggered when a pedestrian presses the button during the normal cycle.
- Depending on when the button is pressed, different actions are taken:
  
| Scenario | Behavior |
|---------|----------|
| Pressed during **Red** | Switch to yellow immediately (5s), then allow pedestrian green. |
| Pressed during **Yellow** (heading to Red) | Complete blinking, then allow pedestrian green. |
| Pressed during **Yellow** (heading to Green) | Continue normal cycle, then allow pedestrian green. |
| Pressed during **Green** (for pedestrians) | No action taken. |

## 🔧 Tools & Tech
- Language: **C**
- Platform: **Embedded C**
- Environment: Simulated for AVR or equivalent setup

## 🎥 Demo

You can view a live demonstration of the application via this link:  
[🔗 Watch Recording](https://nileuniversity-my.sharepoint.com/:v:/g/personal/mamostafa_nu_edu_eg/EUmxBzr0ThpMkBM9sn7TTzsBpVeDA_SGMLlk-X8_MAWu6Q?e=ghdJTa)

---

## 📚 Developed as part of:
> 🇪🇬 **Ministry of Communications and Information Technology** – Egypt FWD Embedded Systems Nanodegree, powered by **Udacity**.

