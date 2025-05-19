1. What is Logging in Python?
    Logging is a module that sends messages(errors, warning, fatal(error when its fully cooked)) from the application to the user.
    There are five log levels: DEBUG, INFO, WARNING, ERROR, CRITICAL. Warning, error and fatal are automatically configured. For debug and info you must do it yourself.
    1. Debug: detailed information used for diagnosing problems; typically only of interest during development.
    2. Info: General information about the application's execution, such as milestones or successful operations.
    3. Warning: indicates a potential problem or unexpected situation that does not necessarily hinder the application's operation.
    4. Error: indicates a more serious issue that has caused a failure in a specific operation, but the application can continue running.
        1. How to effectively use "Error"?
            1. Never ignore an exception that transmits an error silently. If you handle an exception that
            notifies you of an error, log that error.
            2. Never raise and log an error. If you are raising an exception, the caller has the ability to decide
            whether it is truly an error situation, or whether they were expecting the issue to occur. They
            can then decide whether to log it following the previous rule, to handle it, or to re-raise it.
    5. Critical: a very serious error that indicates a severe problem preventing the application from continuing to run.

2. Why is Logging important?
    It's considered the best way to let the user know what the app is doing. It's useful for debugging and auditing. 

3. When to use Logging?
    The instances for which logging should be used are debugging, error tracking, monitoring an app and info tracking.

4. How to use Logging?
    Example on .py file.

    

