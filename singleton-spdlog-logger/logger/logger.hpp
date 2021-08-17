#pragma once

class Logger {
public:
    static Logger& get() {
        static Logger logger;
        return logger;
    }

    Logger(Logger const&) = delete;
    Logger(Logger&&) = delete;
    Logger& operator=(Logger const&) = delete;
    Logger& operator=(Logger &&) = delete;

    static void info();

private:
    void infoImpl();

    Logger() { };
    ~Logger() { };
};
