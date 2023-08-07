#pragma once

#include <spdlog/logger.h>
#include <iostream>

namespace nrlog {

    class Log
    {
        using Logger = std::shared_ptr<spdlog::logger>;
    public:
        enum class Pattern
        {
            None = 0,
            Line, Simple
        };

    public:
        static void Init();
        static void SetPattern( Pattern p );
        static void SetPattern( const char* appName, const char* format );
        static Logger GetNativeLogger();

    private:
        inline static bool s_Initialized = false;

        inline static Pattern s_CurrentPattern;
        inline static std::shared_ptr<spdlog::logger> s_Logger;
    };
}

#pragma region CoreDefines 

#define NR_TRACE(...) \
    nrlog::Log::Init(); \
    nrlog::Log::SetPattern( nrlog::Log::Pattern::Simple ); \
    nrlog::Log::GetNativeLogger()->trace(__VA_ARGS__);

#define NR_DEBUG(...) \
    nrlog::Log::Init(); \
    nrlog::Log::SetPattern( nrlog::Log::Pattern::Simple ); \
    nrlog::Log::GetNativeLogger()->debug(__VA_ARGS__);

#define NR_INFO(...) \
    nrlog::Log::Init(); \
    nrlog::Log::SetPattern( nrlog::Log::Pattern::Simple ); \
    nrlog::Log::GetNativeLogger()->info(__VA_ARGS__);

#define NR_WARN(...) \
    nrlog::Log::Init(); \
    nrlog::Log::SetPattern( nrlog::Log::Pattern::Simple ); \
    nrlog::Log::GetNativeLogger()->warn(__VA_ARGS__);

#define NR_ERROR(...) \
    nrlog::Log::Init(); \
    nrlog::Log::SetPattern( nrlog::Log::Pattern::Simple ); \
    nrlog::Log::GetNativeLogger()->error(__VA_ARGS__);

#define NR_CRITICAL(...) \
    nrlog::Log::Init(); \
    nrlog::Log::SetPattern( nrlog::Log::Pattern::Simple ); \
    nrlog::Log::GetNativeLogger()->critical(__VA_ARGS__);



#define NR_LINE_TRACE(...) \
    nrlog::Log::Init(); \
    nrlog::Log::SetPattern( nrlog::Log::Pattern::Line ); \
    nrlog::Log::GetNativeLogger()->trace(__VA_ARGS__);

#define NR_LINE_DEBUG(...) \
    nrlog::Log::Init(); \
    nrlog::Log::SetPattern( nrlog::Log::Pattern::Line ); \
    nrlog::Log::GetNativeLogger()->debug(__VA_ARGS__);

#define NR_LINE_INFO(...) \
    nrlog::Log::Init(); \
    nrlog::Log::SetPattern( nrlog::Log::Pattern::Line ); \
    nrlog::Log::GetNativeLogger()->info(__VA_ARGS__);

#define NR_LINE_WARN(...) \
    nrlog::Log::Init(); \
    nrlog::Log::SetPattern( nrlog::Log::Pattern::Line ); \
    nrlog::Log::GetNativeLogger()->warn(__VA_ARGS__);

#define NR_LINE_ERROR(...) \
    nrlog::Log::Init(); \
    nrlog::Log::SetPattern( nrlog::Log::Pattern::Line ); \
    nrlog::Log::GetNativeLogger()->error(__VA_ARGS__);

#define NR_LINE_CRITICAL(...) \
    nrlog::Log::Init(); \
    nrlog::Log::SetPattern( nrlog::Log::Pattern::Line ); \
    nrlog::Log::GetNativeLogger()->critical(__VA_ARGS__);

#pragma endregion