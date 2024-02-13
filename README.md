Without Kokkos, using SFML's window.display() and window.setFramerateLimit(1)
will print `frame` every second with negligible CPU usage, as expected.

With Kokkos, it also prints `frame` every second, but the CPU usage is very
high.

---

Inspecting via NSight shows that after initialization work, sfml_nokokkos has a
single thread that wakes every second for <10ms each time. In sfml_kokkos, one
thread behaves similarly but there are 11 other threads (I have 12 CPUs) that
keep yielding and causes the CPU usage to stay at 100%.

It's the `Kokkos::Threads` thread pool. This somewhat implies that this Kokkos
backend isn't suitable for realtime applications built with SFML.
