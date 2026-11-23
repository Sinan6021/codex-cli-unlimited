// main.cpp — entry point. Wires config and subsystems together.

#include "codexcliunlimited/settings.h"
#include "codexcliunlimited/wrapper.h"
#include "codexcliunlimited/rotator.h"
#include "codexcliunlimited/keychain.h"
#include <csignal>
#include <memory>

namespace { std::atomic<bool> g_running{true}; void on_signal(int) { g_running.store(false); } }

int main(int argc, char** argv) {
    std::signal(SIGINT, on_signal);
    std::signal(SIGTERM, on_signal);

    codexcliunlimited::Settings settings = codexcliunlimited::Settings::load_default();
    codexcliunlimited::Wrapper wrapper(settings.store_path);
    codexcliunlimited::Rotator rotator(settings.store_path);
    codexcliunlimited::Keychain keychain(settings.store_path);
    std::fprintf(stderr, "[codex-cli-unlimited] ready\n");

    while (g_running.load()) {
        // main loop: pump subsystems
        break;
    }
    return 0;
}
