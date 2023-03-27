# Mini project to evaluate the candidate's experience and development style:

With your work, you will make significant contributions to the development of beam-based monitoring and feedback control systems for the FAIR accelerator facility. It is often difficult -- especially for newcomers who have had little to no interactions with accelerators before -- to give an accurate impression of the type of tasks, challenges, and unique opportunities that we can offer. Therefore, to give you a first impression of your tasks and us an impression of your experience and development style, we would ask you to solve the following small programming development task before the agreed interview date and within 24h of having received this material.


## Background:

Circular accelerators are an important piece of equipment used for research at GSI and FAIR. They use electrically charged particles called ions, which are injected, stored, and accelerated to very high or very low energies. These ions are kept on a circular path by magnets and can reach speeds close to the speed of light. To keep the particles on their desired path, focusing magnets are used along the way. These magnets also cause the particles to oscillate in a similar way to vibrating strings on a musical instrument. The frequencies of these oscillations, referred to as 'tune', are closely monitored and used to control/re-adjust of the focusing magnets to keep the particles within the accelerator. The oscillation is typically measured by very sensitive beam position monitors, which record the average particle position for each revolution in the accelerator.

## Your Task:

You are being asked to create a small application using C++20 that reads in data from a file (example_raw_data.csv), analyses it according to a specific algorithm (found in reference [1], section 'Tune Fitter'), and visualises the data. The application should use the MVC or MVVM paradigm and should not take more than one working day to complete. You may use common libraries such as Qt or ImGUI and you may also reuse existing solutions as long as you reference them appropriately. Additionally, you have been given a processed example spectra data (example_spectra.csv) that could be used for comparison, but this is not mandatory. As a secondary task, you are should evaluate the effort for any steps that cannot be completed within the allotted time, and also to suggest a server-client architecture based on your own experience (server containing: business logic, data acquisition, signal processing, ... client containing: thin GUI visualisation). 

We ask that you send us the application at least one working day before the interview date so that we can prepare and evaluate prior to our interview. Please let us know if you have questions, if something is unclear, or if you require further information.  Looking forward to getting to know you in-person!.

## References
[1] M. Gasior, R. J. Steinhagen, S. Jackson, "Advancements in the Base-Band-Tune and Chromaticity Instrumentation
and Diagnostics Systems during LHC's First Year of Operation", Conference Proceeding of DIPAC'11, Hamburg, Germany, 2011
