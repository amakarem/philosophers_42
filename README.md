# philosophers_42 🍽️

A C simulation of the Dining Philosophers problem—one of the classic concurrency challenges, implemented per the 42 curriculum specifications.

---

## 📌 Project Overview

- Simulates N philosophers sitting around a table, each alternating between **thinking**, **eating**, and **sleeping**.
- Shared forks (mutex-protected) between philosophers, with exactly as many forks as philosophers.
- A philosopher must pick up both left and right forks to eat—incorrect synchronization can result in **deadlock**, **starvation**, or **race conditions** :contentReference[oaicite:1]{index=1}.

---

## ⚙️ Features & Requirements

### ✅ Mandatory (threads + mutexes)

- Each **philosopher** is represented by a **thread**, each **fork** by a **pthread_mutex_t**.
- Philosophers pick up forks in a deadlock-safe order:
  - Example: **even-indexed** philosophers pick up **left fork first**, **odd-indexed** pick up **right first** :contentReference[oaicite:2]{index=2}.
- Event logging with **timestamp**, philosopher ID, and action:
  - `has taken a fork`, `is eating`, `is sleeping`, `is thinking`, `died`.
- Core parameters via command-line:
  1. number_of_philosophers  
  2. time_to_die (ms)  
  3. time_to_eat (ms)  
  4. time_to_sleep (ms)  
  5. [optional] number_of_times_each_philosopher_must_eat :contentReference[oaicite:3]{index=3}
- Program ends when **a philosopher dies**, or when **all** have eaten the optional required number of times.
- No global variables permitted; strict resource cleanup and no memory leaks.

### 🌟 Bonus (optional)

- **Processes + semaphores** version to simulate philosophers with separate processes instead of threads.
- Inter-process synchronization via **named or unnamed semaphores**.
- Enhanced logging and cleanup routines adapted for multi-process environment.

---

## 🛠️ Installation & Build

Dependencies:
- `gcc`
- `pthread` library
- (Bonus) `semaphore.h`, support for `fork()`

```bash
git clone https://github.com/amakarem/philosophers_42.git
cd philosophers_42
make             # builds mandatory part: ./philo
make bonus       # builds bonus part: ./philo_bonus (if implemented)

---

## Usage

./philo <#philos> <t_die_ms> <t_eat_ms> <t_sleep_ms> [#times_each_must_eat]
