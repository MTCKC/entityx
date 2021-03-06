/*
 * Copyright (C) 2012 Alec Thomas <alec@swapoff.org>
 * All rights reserved.
 *
 * This software is licensed as described in the file COPYING, which
 * you should have received as part of this distribution.
 *
 * Author: Alec Thomas <alec@swapoff.org>
 */

#include "entityx/Event.h"

namespace entityx {

BaseEvent::Family BaseEvent::family_counter_ = 0;


EventManager::EventManager() {
}

EventManager::~EventManager() {
}

void EventManager::emit(const BaseEvent &event) {
  auto sig = signal_for(static_cast<size_t>(event.my_family()));
  sig->emit(&event);
}

}  // namespace entityx
