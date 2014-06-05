Feature: Testing Test Enviroment Works

  Scenario: Access homepage
    When I go to homepage
    Then I should see "Baltimore"
    Then the response status code should be 200
