Feature: Testing Test Enviroment Works

  @api
  Scenario: Access homepage
    Given I am logged in as a user with the "editor" role
    When I go to homepage
    Then I should see "Baltimore"
    Then the response status code should be 200
