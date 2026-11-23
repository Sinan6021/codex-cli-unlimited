// rotator.cpp — part of codex-cli-unlimited.

#include "codexcliunlimited/rotator.h"

#include <cstdio>

namespace codexcliunlimited {

Rotator::Rotator(const std::string& config_path)
    : config_path_(config_path) {}

void Rotator::configure(const std::string& key, const std::string& value) {
    if (key == "verbose") verbose_ = (value == "true");
}

bool Rotator::run() {
    if (verbose_) std::fprintf(stderr, "[codex-cli-unlimited] rotator: run\n");
    // core logic lives here
    return true;
}

}  // namespace codexcliunlimited
