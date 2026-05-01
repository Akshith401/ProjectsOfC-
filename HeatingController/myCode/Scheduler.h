/**
 * @class Scheduler
 * @brief Manages time-based temperature adjustments for heating control.
 *
 * Scheduler handles scheduled modes like night/day temperature profiles.
 * Night mode applies a reduced temperature automatically to save energy.
 *
 * Responsibilities:
 *  - Track whether night mode is active.
 *  - Update schedule based on current time.
 *  - Provide temperature modifier for ThermostatLogic.
 *
 * State:
 *  - nightModeActive : true if night mode is active.
 *
 * Methods:
 *  - update() : checks time and updates @c nightModeActive.
 *  - getTemperatureModifier() : returns temperature offset.
 */
class Scheduler {
private:
    bool nightModeActive; ///< True when night schedule is active.

public:
    /** @brief Initializes scheduler with day mode active by default. */
    Scheduler();
    virtual ~Scheduler();

    /**
     * @brief Updates schedule mode based on current time.
     *
     * Call periodically. Sets @c nightModeActive true during night hours,
     * false during day.
     */
    void update();

    /**
     * @brief Returns a temperature modifier based on active schedule.
     *
     * @return Negative value if night mode active, zero otherwise.
     */
    float getTemperatureModifier() const;
};
