#pragma once

#include <cstdint>
#include <functional>
#include <thread>
#include <vector>

namespace Alchemy {

namespace Async {

/// @brief A handle to a task.
class TaskHandle {
  public:
	TaskHandle() {}
	~TaskHandle() {}

	/// @brief Waits for the task to complete.
	void join();

  private:
	std::thread *thread;
};

/// @brief A task that can be submitted to a pool.
class Task : std::function<void()> {
  public:
	Task() : std::function<void()>() {}
	~Task() {}
};

/// @brief A pool of threads.
class Pool {
  public:
	/// @brief Constructor.
	Pool();

	/// @brief Destructor.
	~Pool();

	/// @brief Gets the number of threads in the pool.
	/// @return The number of threads.
	uint32_t size() const;

	/// @brief Submits a task to the pool.
	TaskHandle submit(Task task);

  private:
	std::vector<std::thread> threads;
};

} // namespace Async

} // namespace Alchemy
