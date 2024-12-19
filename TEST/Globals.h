#pragma once

// Khai báo các hằng số (define const)
constexpr int WIN_WIDTH = 600, WIN_HEIGHT = 768; // màn hình trò chơi
constexpr float SCALE_FACTOR = 1.5f; 
const float gravity = 0.4f; // Trọng lực
const int BIRD_SIZE = 25; // Bird
const float flap_stregth = -9.0f; // sức mạnh mỗi lần đập cánh
const float pipe_velocity = -3.0f; // vận tốc của ống
const int PIPE_GAP = 320; // khoảng cách giữa ống trên và ống dưới
const int PIPE_WIDTH = 50; // chiều rộng của ống
const int SPAWN_FREQUENCY = 65; // khoảng cách giữa các cặp ống