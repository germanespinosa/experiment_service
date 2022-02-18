#pragma once
#include <experiment/experiment_messages.h>
#include <tcp_messages.h>
#include <cell_world.h>

namespace experiment {
    struct Experiment_client : tcp_messages::Message_client {

        Routes(
                Add_route("experiment_started", on_experiment_started, Start_experiment_response);
                Add_route("episode_started", on_episode_started, std::string);
                Add_route("episode_finished", on_episode_finished);
                Add_route("experiment_finished", on_experiment_finished, std::string);
        )

        virtual void on_experiment_started(const Start_experiment_response &experiment) {};

        virtual void on_episode_started(const std::string &experiment_name) {};

        virtual void on_episode_finished() {};

        virtual void on_experiment_finished(const std::string &experiment_name) {};

        Start_experiment_response start_experiment(const cell_world::World_info &world, const std::string &subject_name, int duration,
                         const std::string &prefix = "", const std::string &suffix = "");

        bool start_episode(const std::string &experiment_name);

        bool finish_episode();

        bool finish_experiment(const std::string &experiment_name);

        Get_experiment_response get_experiment(const std::string &experiment_name);

        bool is_active(const std::string &experiment_name);

        bool connect (const std::string &ip);

        bool set_tracking_service_ip(const std::string &ip);

        bool capture(unsigned int frame);

    };
}